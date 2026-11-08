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

void SystemRezerwacji::dodajPojazd(const Pojazd& pojazd){
    katalog_pojazdow.push_back(pojazd);
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

}

void SystemRezerwacji::naliczKare(int id_pracownik, int id_klient, double kwota)
{
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
        cout<<endl;
        cout<<"Menu rezerwacji - Widok Pracownika"<<endl;
        cout<<" 1. Wyświetl Pojazdy \n 2. Dodaj Pojazd \n 3. Usuń Pojazd \n 4. Wyświetl listę rezerwacji \n 0. Wyjdź";
        std::cin>>choice;
        string marka, model, typ, numer_vin;
        switch(choice){
            case 1:

                int n = katalog_pojazdow.size();
                if (n == 0) {
                    cout << "Katalog pojazdów jest pusty.\n";
                    break;
                }
                for(int i = 0; i < n; i++){
                    cout<<endl;
                    cout<<i + 1<<". ===== ";
                    katalog_pojazdow[i].print();
                    cout << endl;
                }
                cout<<" WYBIERZ POJAZD (0 aby pominąć): \n";
                int wybor;
                std::cin>>wybor;
                if(wybor > 0 && wybor <= katalog_pojazdow.size()) {
                    wybierzPojazd(katalog_pojazdow[wybor-1].getNumer_vin(),wybor, true, id_pracownik);
                }
                break;
            case 2:{
                cout << "Podaj markę: ";
                std::cin >> marka;
                cout << "Podaj model: ";
                std::cin >> model;
                cout << "Podaj typ (np. Samochod): ";
                std::cin >> typ;
                cout << "Podaj numer VIN: ";
                std::cin >> numer_vin;
                Pojazd nowyPojazd(marka, model, typ, numer_vin, true);
                dodajPojazd(nowyPojazd);
                cout << "Pojazd został dodany do katalogu.\n";
                break;
            }
            case 3:
  
                cout << "Podaj numer VIN pojazdu do usunięcia: ";
                std::cin >> numer_vin;
                cout<<endl;
                if (usunPojazd(numer_vin)) {
                    cout << "Pojazd został usunięty.\n";
                } else {
                    cout << "Nie znaleziono pojazdu o podanym numerze VIN.\n";
                }
                break;

            case 4:
                cout << "\n=== Aktywne rezerwacje w systemie ===n";
                if (aktywne_rezerwacje.empty()) {
                    cout << "Brak rezerwacji w systemie.\n";
                    break;
                }

                for (size_t i = 0; i < aktywne_rezerwacje.size(); i++) {
                    cout << "\n[" << i + 1 << "]\n";
                    aktywne_rezerwacje[i].print();
                    cout << "--------------------------------\n";
                }

                cout << "Podaj numer rezerwacji do zatwierdzenia (0 aby pominąć): ";
                int nrRez;
                std::cin >> nrRez;
                if (nrRez > 0 && nrRez <= aktywne_rezerwacje.size()) {
                    zatwierdzRezerwacje(id_pracownik, aktywne_rezerwacje[nrRez-1]);
                    cout << "Rezerwacja została zatwierdzona.\n";
                }
                break;
            case 0:
                petla=false;
                break;
            default:
                cout<<"Zła opcja podaj poprawną. \n";
                break;
        }

    }
}

void SystemRezerwacji::menuKlient(Klient klient){
    bool petla = true;
    while(petla){
        int choice;
        cout<<endl;
        cout<<"Menu rezerwacji - Widok Pracownika"<<endl;
        cout<<" 1. Wyświetl dostępne pojazdy \n 2. Wyświetl listę rezerwacji \n 0. Wyjdź";
        std::cin>>choice;
        switch(choice){
            {case 1:
                cout<<"\n DOSTĘPNE POJAZDY \n";
                vector<int> dostepne;
                int n = katalog_pojazdow.size();
                for(int i =0 ; i<n; i++){
                    if(katalog_pojazdow[i].getDostepnosc()) {
                        cout << dostepne.size() + 1 << ". ===";
                        katalog_pojazdow[i].print();
                        cout << endl;
                        dostepne.push_back(i);
                    }
                }
                if (dostepne.empty()) {
                    cout << "Brak dostępnych pojazdów w tej chwili.\n";
                    break;
                }
                cout<<" Wybierz dnumer pojazdu z listy, lub 0 aby anulować ";
                int wybor;
                std::cin>>wybor;
                cout<<endl;
                if(wybor > 0 && wybor<= dostepne.size()){
                    int indeks_temp = dostepne[wybor-1];
                    wybierzPojazd(katalog_pojazdow[indeks_temp].getNumer_vin(), indeks_temp, false, klient.getId());
                }
                wybierzPojazd(katalog_pojazdow[wybor-1].getNumer_vin(),wybor, false, klient.getId());
                break;}
            case 2:
                cout << "\n=== Twoje rezerwacje ===\n";
                const auto& rezerwacjeKlienta = klient.getLista_rezerwacji();
                if (rezerwacjeKlienta.empty()) {
                    cout << "Nie masz jeszcze żadnych rezerwacji.\n";
                } else {
                    for (const auto& rez : rezerwacjeKlienta) {
                        rez.print();
                        cout << "\n---------------------------\n";
                    }
                }

                
                break;
            case 0:
                petla=false;
                break;
            default:
                cout<<"Zła opcja podaj poprawną";
                break;
        }

    }
}

void SystemRezerwacji::menu()
{   
    bool petla = true;
    while(petla){
        int user;
        cout<<"Menu rezerwacji"<<endl;
        cout<<"1. Klient"<<endl<<" 2. Pracownik"<<endl<<"0. Zakończ";
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
                    petla = false;
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
                petla = false;
                menuPracownik(id);
            } else {
                cout << "Nie znaleziono pracownika o podanym ID!" << endl;
            }
            break;
        case 0:
            petla = false;
            break;
        default:
            cout<<"Zła opcja podaj poprawną";
            break;
        }
    }
}

bool SystemRezerwacji::zarezerwuj(int id_klient, const Date& data, int okres, const std::string& metoda, PozycjaRezerwacji pozycja){
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
    vector<PozycjaRezerwacji> pozycje = {pozycja};


    Rezerwacja nowaRezerwacja(idRezerwacji, data, dataZwrotu, pozycje, platnosc, false);

    aktywne_rezerwacje.push_back(nowaRezerwacja);

    klient->dodajRezerwacje(nowaRezerwacja);

    string vinPojazdu = pozycja.getPojazd().getNumer_vin();
    for (auto& p : katalog_pojazdow) {
        if (p.getNumer_vin() == vinPojazdu) {
            p.setDostepnosc(false);
            break;
        }
    }

    return true;
}

void SystemRezerwacji::wybierzPojazd(const std::string& numer_vin, int id_pojazdu, bool pracownik, int osoba_id){
    if (pracownik)
    {
        
        return;
    }
    if (!pracownik){
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
    
        Pojazd wybranyPojazd;
        bool znaleziony = false;
        for (const auto& p : katalog_pojazdow){
            if(p.getNumer_vin()==numer_vin){
                wybranyPojazd = p;
                znaleziony = true;
                break;
            }
        }
        if (!znaleziony || !wybranyPojazd.getDostepnosc()) {
        cout << "Błąd: Wybrany pojazd jest niedostępny!\n";
        return;
        }

        PozycjaRezerwacji pozycja(wybranyPojazd);

        if (zarezerwuj(osoba_id, dataRezerwacji, okres, metoda, pozycja)) {
            cout << "Sukces! Pojazd został pomyślnie zarezerwowany.\n";
        } else {
            cout << "Błąd podczas tworzenia rezerwacji.\n";
    }
    }
}

