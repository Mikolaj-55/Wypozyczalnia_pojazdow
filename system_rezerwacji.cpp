#include "system_rezerwacji.hpp"

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


void SystemRezerwacji::menu()
{

}

bool SystemRezerwacji::zarezerwuj(int id_klient, const Pojazd& pojazd, const Date& data, int okres, const std::string& metoda)
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