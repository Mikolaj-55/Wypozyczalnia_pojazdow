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
        cin>>choice;
        switch(choice){
            case 1:

                int n = katalog_pojazdow.size();
                for(int i =0 ; i<n; i++){
                    cout<<endl;
                    cout<<i<<". ===== ";
                    katalog_pojazdow[i].print();
                }
                int wybor;
                cin>>wybor;
                wybierzPojazd(katalog_pojazdow[wybor-1].getNumer_vin(),wybor, true, id_pracownik);
                break;
            case 2:



                break;
            case 3:
                break;
            case 4:

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

void SystemRezerwacji::menuKlient(Klient klient){
    bool petla = true;
    while(petla){
        int choice;
        cout<<endl;
        cout<<"Menu rezerwacji - Widok Pracownika"<<endl;
        cout<<" 1. Wyświetl dostępne pojazdy \n 2.  \n 3. Wyświetl listę rezerwacji \n 0. Wyjdź";
        cin>>choice;
        switch(choice){
            case 1:

                int n = katalog_pojazdow.size();
                for(int i =0 ; i<n; i++){
                    cout<<endl;
                    cout<<i+1<<". ===== ";
                    katalog_pojazdow[i].print();
                }
                int wybor;
                cin>>wybor;
                wybierzPojazd(katalog_pojazdow[wybor-1].getNumer_vin(),wybor, false, klient.getId());
                break;
            case 2:


                
                break;
            case 3:
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
        cin>>user;
        int id;
        Klient klient;
        switch (user)
        {
        case 1:
            cout << "Podaj id klienta:" << endl; 
            cin >> id;
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
            cin >> id;
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


bool SystemRezerwacji::zarezerwuj(int id_klient, const Date& data, int okres, const std::string& metoda, PozycjaRezerwacji pojazd)
{

    

}

void SystemRezerwacji::wybierzPojazd(const std::string& numer_vin, int id_pojazdu, bool pracownik, int osoba_id)
{
    

}

void SystemRezerwacji::dodajPojazd(int id_pracownik, const Pojazd& pojazd)
{

}

bool SystemRezerwacji::usunPojazd(int id_pracownik, const std::string& numer_vin)
{
    
}

void SystemRezerwacji::zatwierdzRezerwacje(int id_pracownik, int id_klient, const Rezerwacja& rezerwacja)
{

}

bool SystemRezerwacji::zamknijRezerwacje(int id_pracownik, int id_klient, const Rezerwacja& rezerwacja)
{
    
}

void SystemRezerwacji::naliczKare(int id_pracownik, int id_klient, double kwota)
{
    
}