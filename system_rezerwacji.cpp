#include "system_rezerwacji.hpp"
#include <iostream>


using namespace std;
SystemRezerwacji::SystemRezerwacji(double stawka_dniowa, const std::vector<PracownikObslugi>& lista_pracownikow, const std::vector<Klient>& lista_klientow, const std::vector<Pojazd>& katalog_pojazdow, const std::vector<Rezerwacja>& aktywne_rezerwacje)
    : stawka_dniowa(stawka_dniowa), lista_pracownikow(lista_pracownikow), lista_klientow(lista_klientow), katalog_pojazdow(katalog_pojazdow), aktywne_rezerwacje(aktywne_rezerwacje) {}

SystemRezerwacji::~SystemRezerwacji() = default;


double SystemRezerwacji::getStawka_dniowa() const
{
    return stawka_dniowa;
}

const std::vector<PracownikObslugi>& SystemRezerwacji::getLista_pracownikow() const
{
    return lista_pracownikow;
}

const std::vector<Klient>& SystemRezerwacji::getLista_klientow() const
{
    return lista_klientow;
}

const std::vector<Pojazd>& SystemRezerwacji::getKatalog_pojazdow() const
{
    return katalog_pojazdow;
}

const std::vector<Rezerwacja>& SystemRezerwacji::getAktywne_rezerwacje() const
{
    return aktywne_rezerwacje;
}

void SystemRezerwacji::setStawka_dniowa(double val)
{
    stawka_dniowa=val;
}

void SystemRezerwacji::setLista_pracownikow(const std::vector<PracownikObslugi>& val)
{
    lista_pracownikow=val;
}

void SystemRezerwacji::setLista_klientow(const std::vector<Klient>& val)
{
    lista_klientow=val;
}

void SystemRezerwacji::setKatalog_pojazdow(const std::vector<Pojazd>& val)
{
    katalog_pojazdow=val;
}

void SystemRezerwacji::setAktywne_rezerwacje(const std::vector<Rezerwacja>& val)
{
    aktywne_rezerwacje=val;
}

bool SystemRezerwacji::dodajPojazd(const Pojazd& pojazd){
    for (const auto& p : katalog_pojazdow){
        if(p.getNumer_vin()==pojazd.getNumer_vin()){
            cout<<"Pojazd o takim numerze VIN już istnieje!\n";
            return false;
        }
    }
    katalog_pojazdow.push_back(pojazd);
    return true;
}

bool SystemRezerwacji::usunPojazd(const std::string& numer_vin)
{
    for (auto it = katalog_pojazdow.begin(); it != katalog_pojazdow.end(); ++it) {
        if (it->getNumer_vin() == numer_vin) {
            katalog_pojazdow.erase(it);
            return true;
        }
    }
    return false;
}

void SystemRezerwacji::zatwierdzRezerwacje(int id_pracownik, const Rezerwacja& rezerwacja)
{
    if (!czyPracownik(id_pracownik)) return;
    
    for (auto& rez : aktywne_rezerwacje) {
        if (rez.getId_rezerwacji() == rezerwacja.getId_rezerwacji()) {
            if(rez.getPotwierdzenie()){
                cout<<" Podana rezerwacja jest już zatwierdzona. "<<endl;
                return;
            }
            rez.setPotwierdzenie(true);
            break;
        }
    }
    Klient* docelowyKlient = nullptr;
    for (auto& klient : lista_klientow) {
        const auto& listaRezerwacjiKlienta = klient.getLista_rezerwacji();
        for (const auto& rez : listaRezerwacjiKlienta) {
            if (rez.getId_rezerwacji() == rezerwacja.getId_rezerwacji()) {
                docelowyKlient = &klient;
                break;
            }
        }
        if (docelowyKlient != nullptr) {
            break;
        }
    }

    if (docelowyKlient != nullptr) {
        vector<Rezerwacja> lista = docelowyKlient->getLista_rezerwacji();
        for (auto& rez : lista) {
            if (rez.getId_rezerwacji() == rezerwacja.getId_rezerwacji()) {
                rez.setPotwierdzenie(true);
                break;
            }
        }
        docelowyKlient->setLista_rezerwacji(lista);
    }

}

bool SystemRezerwacji::zamknijRezerwacje(int id_pracownik, int id_klient, const Rezerwacja& rezerwacja)
{
    if (!czyPracownik(id_pracownik)) return false;

    for(auto it = aktywne_rezerwacje.begin(); it!=aktywne_rezerwacje.end();++it){
        if(it->getId_rezerwacji()==rezerwacja.getId_rezerwacji()){
            for(const auto& poz : it->getPozycje()){
                string vin = poz.getPojazd().getNumer_vin();
                for(auto& p : katalog_pojazdow){
                    if(p.getNumer_vin()==vin){
                        p.setDostepnosc(true);
                        break;
                    }
                }
            }
        }
    }

    Klient* klient = znajdzKlienta(id_klient);
    if(klient){
        klient->usunRezerwacje(rezerwacja.getId_rezerwacji());
        return true;
    }
    return false;

}

void SystemRezerwacji::naliczKare(int id_pracownik, int id_klient, double kwota)
{
    if(!czyPracownik(id_pracownik)) return;

    Klient* klient = znajdzKlienta(id_klient);
    if (klient){
        klient->dodajKare(kwota);
    }
}

Klient* SystemRezerwacji::znajdzKlienta(int id){
    int n = lista_klientow.size();
    for(int i=0;i<n;i++){
        if(lista_klientow[i].getId()==id){
            return &lista_klientow[i];
        }
    }
    return nullptr;
}

bool SystemRezerwacji::czyPracownik(int id){
    int n = lista_pracownikow.size();
    for(int i=0;i<n;i++){
        if(lista_pracownikow[i].getId()==id){
            return true;
        }
    }
    return false;
}

void SystemRezerwacji::menuPracownik(int id_pracownik){
    bool petla = true;
    while(petla){
        int choice;
        std::cout<<endl;
        std::cout<<"Menu rezerwacji - Widok Pracownika"<<endl;
        std::cout<<" 1. Wyświetl Pojazdy \n 2. Dodaj Pojazd \n 3. Usuń Pojazd \n 4. Wyświetl listę rezerwacji \n 0. Wyjdź\n";
        std::cin>>choice;
        string marka, model, typ, numer_vin;
        switch(choice){
            case 1:{

                int n = katalog_pojazdow.size();
                if (n == 0) {
                    std::cout << "Katalog pojazdów jest pusty.\n";
                    break;
                }
                for(int i = 0; i < n; i++){
                    std::cout<<endl;
                    std::cout<<i + 1<<". ===== ";
                    katalog_pojazdow[i].print();
                    std::cout << endl;
                }
                cout<<" WYBIERZ POJAZD (0 aby pominąć): \n";
                int wybor;
                std::cin>>wybor;
                if(wybor > 0 && wybor <= katalog_pojazdow.size()) {
                    wybierzPojazd(katalog_pojazdow[wybor-1].getNumer_vin(),true);
                }
                break;
            }
            case 2:{
                std::cout << "Podaj markę: ";
                std::cin >> marka;
                std::cout << "Podaj model: ";
                std::cin >> model;
                std::cout << "Podaj typ (np. Samochod): ";
                std::cin >> typ;
                std::cout << "Podaj numer VIN: ";
                std::cin >> numer_vin;
                Pojazd nowyPojazd(marka, model, typ, numer_vin, true);
                if (dodajPojazd(nowyPojazd)){
                    std::cout << "Pojazd został dodany do katalogu.\n";
                }
                break;
            }
            case 3:{
  
                std::cout << "Podaj numer VIN pojazdu do usunięcia: ";
                std::cin >> numer_vin;
                std::cout<<endl;
                if (usunPojazd(numer_vin)) {
                    std::cout << "Pojazd został usunięty.\n";
                } else {
                    std::cout << "Nie znaleziono pojazdu o podanym numerze VIN.\n";
                }
                break;}

            case 4:{
                std::cout << "\n=== Aktywne rezerwacje w systemie ===\n";
                if (aktywne_rezerwacje.empty()) {
                    std::cout << "Brak rezerwacji w systemie.\n";
                    break;
                }

                for (size_t i = 0; i < aktywne_rezerwacje.size(); i++) {
                    std::cout << "\n[" << i + 1 << "]\n";
                    aktywne_rezerwacje[i].print();
                    std::cout << "--------------------------------\n";
                }
                cout<<endl<<" 1. Zatwierdzenie rezerwacji \n 2. Zamknięcie rezerwacji \n 3. Dodaj Karę \n 0. Wyjdź"<<endl;
                int opcja, nrRez;
                cin>>opcja;
                if(opcja==1){
                    std::cout << "\nPodaj numer rezerwacji do zatwierdzenia (0 aby cofnąć): ";
                    std::cin >> nrRez;
                    if (nrRez > 0 && nrRez <= aktywne_rezerwacje.size()) {
                        if(!aktywne_rezerwacje[nrRez-1].getPotwierdzenie()){
                            zatwierdzRezerwacje(id_pracownik, aktywne_rezerwacje[nrRez-1]);
                            std::cout << "Rezerwacja została zatwierdzona.\n";
                        }else{
                            cout << "Rezerwacja jest już potwierdzona. \n";
                        }
                        
                    }
                }else if(opcja==2){
                    cout<< "\nPodaj numer rezerwacji do zamknięcia (0 aby cofnąć): ";
                    cin>>nrRez;
                    if (nrRez > 0 && nrRez <= aktywne_rezerwacje.size()) {
                        Klient* docelowyKlient = nullptr;
                        Rezerwacja& rezerwacja = aktywne_rezerwacje[nrRez-1];
                        for (auto& klient : lista_klientow) {
                            const auto& listaRezerwacjiKlienta = klient.getLista_rezerwacji();
                            for (const auto& rez : listaRezerwacjiKlienta) {
                                if (rez.getId_rezerwacji() == rezerwacja.getId_rezerwacji()) {
                                    docelowyKlient = &klient;
                                }
                            }
                        }
                        zamknijRezerwacje(id_pracownik,docelowyKlient->getId(),rezerwacja);
                        cout<<"\nZAMKNIĘTO REZERWACJE "<<rezerwacja.getId_rezerwacji()<<endl;
                        aktywne_rezerwacje.erase(aktywne_rezerwacje.begin()+nrRez-1);
                    }
                
                }else if(opcja==3){
                    cout<< "\nPodaj numer rezerwacji do dodania kary (0 aby cofnąć): ";
                    cin>>nrRez;
                    if (nrRez > 0 && nrRez <= aktywne_rezerwacje.size()) {
                        cout<<" \n Podaj kwotę kary :";
                        int kara;
                        cin>>kara;
                        Klient* docelowyKlient = nullptr;
                        Rezerwacja& rezerwacja = aktywne_rezerwacje[nrRez-1];
                        for (auto& klient : lista_klientow) {
                            const auto& listaRezerwacjiKlienta = klient.getLista_rezerwacji();
                            for (const auto& rez : listaRezerwacjiKlienta) {
                                if (rez.getId_rezerwacji() == rezerwacja.getId_rezerwacji()) {
                                    docelowyKlient = &klient;
                                    docelowyKlient->dodajKare(kara);
                                    cout<<" Dodano karę do klienta: "<<docelowyKlient->getImie()<<" "<<docelowyKlient->getNazwisko()<<endl;
                                }
                            }
    }
                }
                }
                
                break;}
            case 0:{
                petla=false;
                break;}
            default:{
                std::cout<<"Zła opcja podaj poprawną. \n";
                break;}
        }

    }
}

void SystemRezerwacji::menuKlient(Klient& klient){
    bool petla = true;
    while(petla){
        int choice;
        std::cout<<endl;
        std::cout<<"Menu rezerwacji - Widok Klienta"<<endl;
        std::cout<<" 1. Wyświetl dostępne pojazdy \n 2. Złóż rezerwację \n 3. Wyświetl listę rezerwacji \n 4. Wyświetl nałożone kary \n 0. Wyjdź \n";
        std::cin>>choice;
        switch(choice){
            case 1:{
                std::cout<<"\n DOSTĘPNE POJAZDY \n";
                vector<int> dostepne;
                int n = katalog_pojazdow.size();
                for(int i =0 ; i<n; i++){
                    if(katalog_pojazdow[i].getDostepnosc()) {
                        std::cout << dostepne.size() + 1 << ". ===\n";
                        katalog_pojazdow[i].print();
                        std::cout << endl;
                        dostepne.push_back(i);
                    }
                }
                if (dostepne.empty()) {
                    std::cout << "Brak dostępnych pojazdów w tej chwili.\n";
                    break;
                }
                /*
                std::cout<<" Wybierz numer pojazdu z listy, lub 0 aby anulować ";
                int wybor;
                std::cin>>wybor;
                if(wybor > 0 && klient.getKary() > 0){
                    std::cout << "Nie można złożyć wypożyczenia! Musisz najpierw zapłacić kary!\n";
                    break;
                }
                std::cout<<endl;
                if(wybor > 0 && wybor<= dostepne.size()){
                    int indeks_temp = dostepne[wybor-1];
                    wybierzPojazd(katalog_pojazdow[indeks_temp].getNumer_vin(), indeks_temp, false, klient.getId());
                }
                    */
                break;}
            case 2:{
                if(klient.getKary() > 0){
                    std::cout << "Nie można złożyć rezerwacji! Musisz najpierw zapłacić kary!\n";
                    break;}
                vector<int> dostepne;
                int n = katalog_pojazdow.size();
                for(int i =0 ; i<n; i++){
                    if(katalog_pojazdow[i].getDostepnosc()) {
                        dostepne.push_back(i);
                    }
                }
                if (dostepne.empty()) {
                    std::cout << "Brak dostępnych pojazdów w tej chwili.\n";
                    break;
                }
                int dzien, miesiac, rok, okres;
                string metoda;
                cout<<" \n === Formularz rezewacji === \n";
                cout << "Podaj datę rozpoczęcia (dzień miesiąc rok, np. 15 6 2026): ";
                std::cin >> dzien >> miesiac >> rok;
                Date dataRezerwacji(dzien, miesiac, rok);

                cout << "Podaj okres rezerwacji (liczba dni): ";
                std::cin >> okres;

                cout << "Podaj metodę płatności (np. gotowka, karta): ";
                std::cin >> metoda;
                vector<PozycjaRezerwacji> pozycje={};
                int m=dostepne.size();
                int wybor=1;
                while(wybor!=0){
                    std::cout<<"\n DOSTĘPNE POJAZDY \n";
                    for(int i=0;i<m;i++){
                        std::cout << i + 1 << ". ===\n";
                        katalog_pojazdow[dostepne[i]].print();
                        std::cout << endl;
                    }
                    std::cout<<"\nWybierz numer pojazdu z listy, lub 0 aby anulować.\nJeśli to ostatni pojazd, który chcesz wybrać, wybierz -1\n";
                    std::cin>>wybor;
                    std::cout<<endl;
                    if(wybor > 0 && wybor<= m){
                        int indeks_temp = dostepne[wybor-1];
                        const string& numer_vin=katalog_pojazdow[indeks_temp].getNumer_vin();
                        bool czy_juz_wybrany=false;
                        int k=pozycje.size();
                            for(const auto& p : pozycje){
                                if(p.getPojazd().getNumer_vin()==numer_vin){
                                    std::cout<<"Ten pojazd został już wybrany!\n";
                                    czy_juz_wybrany=true;
                                    break;
                                }
                            }
                        if(!czy_juz_wybrany){
                            PozycjaRezerwacji pozycja(katalog_pojazdow[indeks_temp]);
                            pozycje.push_back(pozycja);
                        }
                    }
                    if(wybor==-1){
                        if(pozycje.empty()){
                        std::cout<<"Wybierz co najmniej jeden pojazd!\n";
                        continue;
                        }
                        break;
                    }
                }
                if(wybor==-1){
                if (zarezerwuj(klient.getId(), dataRezerwacji, okres, metoda, pozycje)) {
                        cout << "Sukces! Pojazdy zostały pomyślnie zarezerwowane.\n";
                    } else {
                        cout << "Błąd podczas tworzenia rezerwacji.\n";
                    }
                }
                break;}
            case 3:{
                std::cout << "\n=== Twoje rezerwacje ===\n";
                const auto& rezerwacjeKlienta = klient.getLista_rezerwacji();
                if (rezerwacjeKlienta.empty()) {
                    std::cout << "Nie masz jeszcze żadnych rezerwacji.\n";
                } else {
                    for (const auto& rez : rezerwacjeKlienta) {
                        rez.print();
                        std::cout << "\n---------------------------\n";
                    }
                }
                break;}
            case 4:{
                std::cout << "Twoje kary: " << klient.getKary() << endl;
                break;}
            case 0:{
                petla=false;
                break;}
            default:{
                std::cout<<"Zła opcja podaj poprawną";
                break;}
        }

    }
}

void SystemRezerwacji::menu(){
    bool petla = true;
    while(petla){
        int user;
        cout<<"Menu rezerwacji"<<endl;
        cout<<"1. Klient"<<endl<<"2. Pracownik"<<endl<<"0. Zakończ \n";
        std::cin>>user;
        int id;
        Klient klient;
        switch (user)
        {
        case 1:
            cout << "Podaj id klienta:" << endl;
            std::cin >> id;
            {
                Klient* znalezionyKlient = znajdzKlienta(id);
                if (znalezionyKlient != nullptr) {
                    menuKlient(*znalezionyKlient);
                } else {
                    cout << "Nie znaleziono klienta o podanym ID!" << endl;
                }
            }
            break;

        case 2:
            cout << "Podaj id pracownika:" << endl;
            std::cin >> id;
            if (czyPracownik(id)) {
                menuPracownik(id);
            } else {
                cout << "Nie znaleziono pracownika o podanym ID!" << endl;
            }
            break;
        case 0:
            petla = false;
            break;
        default:
            cout<<"Zła opcja podaj poprawną"<<endl;
            break;
        }
    }
}

bool SystemRezerwacji::zarezerwuj(int id_klient, const Date& data, int okres, const std::string& metoda, const vector<PozycjaRezerwacji>& pozycje){
    Klient* klient = znajdzKlienta(id_klient);
    if (!klient) {
        return false;
    }
    // data zwrotu
    int d = data.getDay() + okres;
    int m = data.getMonth();
    int r = data.getYear();

    while (d > 30) {
        d -= 30;
        m++;
        if (m > 12) {
            m = 1;
            r++;
        }
    }
    Date dataZwrotu(d, m, r);

    // koszt na podstawie stawki dziennej
    double koszt = okres * stawka_dniowa;
    Platnosc platnosc(metoda, koszt);

    // id rezerwacji
    int idRezerwacji = aktywne_rezerwacje.size() + 1;


    Rezerwacja nowaRezerwacja(idRezerwacji, data, dataZwrotu, pozycje, platnosc, false);

    aktywne_rezerwacje.push_back(nowaRezerwacja);

    klient->dodajRezerwacje(nowaRezerwacja);
    for(const auto& pozycja : pozycje){
        string vinPojazdu = pozycja.getPojazd().getNumer_vin();
        for (auto& p : katalog_pojazdow) {
            if (p.getNumer_vin() == vinPojazdu) {
                p.setDostepnosc(false);
                break;
        }
    }
    }
    return true;
}

void SystemRezerwacji::wybierzPojazd(const std::string& numer_vin, bool pracownik){
    Pojazd* wybranyPojazd = nullptr;
    for (auto& p : katalog_pojazdow) {
            if (p.getNumer_vin() == numer_vin) {
                wybranyPojazd = &p;
                break;
            }
        }
    if (!wybranyPojazd) {
        cout << "Nie znaleziono pojazdu!\n";
        return;
    }
    if (pracownik)
    {
        bool podmenu = true;
        while(podmenu){
            cout << "\n=== ZARZĄDZANIE POJAZDEM ===\n";
            wybranyPojazd->print();
            cout << "\n 1. Zmień status dostępności\n 2. Usuń ten pojazd\n 0. Powrót\n Wybierz: ";
            int opcjaPojazdu;
            cin >> opcjaPojazdu;
            
            if(opcjaPojazdu == 1){
                wybranyPojazd->setDostepnosc(!wybranyPojazd->getDostepnosc());
                cout << "Zmieniono status dostępności pojazdu.\n";
            } 
            else if(opcjaPojazdu == 2){
                string vinDoUsuniecia = wybranyPojazd->getNumer_vin();
                if(usunPojazd(vinDoUsuniecia)){
                    cout << "Pojazd został usunięty.\n";
                    podmenu = false; 
                } else {
                    cout << "Nie udało się usunąć pojazdu.\n";
                }
            } 
            else if(opcjaPojazdu == 0){
                podmenu = false;
            } 
            else {
                cout << "Niepoprawna opcja.\n";
            }
        }

        return;
    }
}

void SystemRezerwacji::dodajRezerwacje(const Rezerwacja& rezerwacja)
{
    for (const auto& r : aktywne_rezerwacje){
        if(r.getId_rezerwacji()==rezerwacja.getId_rezerwacji()){
            cout<<"Rezerwacja o takim ID już istnieje!\n";
            return;
        }
    }
    aktywne_rezerwacje.push_back(rezerwacja);
}

void SystemRezerwacji::dodajPracownika(const PracownikObslugi& pracownik)
{
    for (const auto& p : lista_pracownikow){
        if(p.getId()==pracownik.getId()){
            cout<<"Osoba o takim ID już istnieje!\n";
            return;
        }
    }
    for (const auto& k : lista_klientow){
        if(k.getId()==pracownik.getId()){
            cout<<"Osoba o takim ID już istnieje!\n";
            return;
        }
    }
    lista_pracownikow.push_back(pracownik);
}

void SystemRezerwacji::dodajKlienta(const Klient& klient)
{
    for (const auto& p : lista_pracownikow){
        if(p.getId()==klient.getId()){
            cout<<"Osoba o takim ID już istnieje!\n";
            return;
        }
    }
    for (const auto& k : lista_klientow){
        if(k.getId()==klient.getId()){
            cout<<"Osoba o takim ID już istnieje!\n";
            return;
        }
    }
    lista_klientow.push_back(klient);
}
