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


void SystemRezerwacji::menuPracownik(int id){
    bool petla = true;
    while(petla){
        int choice;
        cout<<endl;
        cout<<"Menu rezerwacji - Widok Pracownika"<<endl;
        cout<<" 1. Wyświetl Pojazdy \n 2. Dodaj Pojazd \n 3. Usuń Pojazd \n 4. Wyświetl listę rezerwacji \n 0. Wyjdź";
        cin>>choice;
        switch(choice){
            case 1:

                // int n = katalog_pojazdow.size();
                // for(int i =0 ; i<n; i++){
                //     cout<<endl<<i;
                // }
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

void SystemRezerwacji::menuKlient(int id){

}

void SystemRezerwacji::menu()
{   
    bool petla = true;
    while(petla){
        int user;
        cout<<"Menu rezerwacji"<<endl;
        cout<<"1. Klient"<<endl<<" 2. Pracownik"<<endl<<"0. Zakończ";
        cin>>user;
        switch (user)
        {
            int id;
        case 1:
            cout<<"Podaj id pracownika"<<endl;
            cin>>id;
            petla = false;
            menuKlient(id);
            break;
        
        case 2:
            cout<<"Podaj id klienta"<<endl;
            cin>>id;
            petla = false;
            menuPracownik(id);
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


bool SystemRezerwacji::zarezerwuj(int id_klient, const Date& data, int okres, const std::string& metoda)
{
    
}

void SystemRezerwacji::wybierzPojazd(const std::string& numer_vin)
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