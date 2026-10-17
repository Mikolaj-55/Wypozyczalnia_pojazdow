#ifndef SYSTEMREZERWACJI_HPP
#define SYSTEMREZERWACJI_HPP

#include "pracownik_obslugi.hpp"
#include "klient.hpp"
#include "pojazd.hpp"
#include "rezerwacja.hpp"

class SystemRezerwacji
{
    private:
        double stawka_dniowa;
        std::vector<PracownikObslugi> lista_pracownikow;
        std::vector<Klient> lista_klientow;
        std::vector<Pojazd> katalog_pojazdow;
        std::vector<Rezerwacja> aktywne_rezerwacje;

    public:
        SystemRezerwacji(double stawka_dniowa, std::vector<PracownikObslugi> lista_pracownikow, std::vector<Klient> lista_klientow, std::vector<Pojazd> katalog_pojazdow, std::vector<Rezerwacja> aktywne_rezerwacje);
        virtual ~SystemRezerwacji();

        double getStawka_dniowa() {return stawka_dniowa;}
        void setStawka_dniowa(double val) {stawka_dniowa = val;}
        std::vector<PracownikObslugi> getLista_pracownikow() {return lista_pracownikow;}
        void setLista_pracownikow(std::vector<PracownikObslugi> val) {lista_pracownikow = val;}
        std::vector<Klient> getLista_klientow() {return lista_klientow;}
        void setLista_klientow(std::vector<Klient> val) {lista_klientow = val;}
        std::vector<Pojazd> getKatalog_pojazdow() {return katalog_pojazdow;}
        void setKatalog_pojazdow(std::vector<Pojazd> val) {katalog_pojazdow = val;}
        std::vector<Rezerwacja> getAktywne_rezerwacje() {return aktywne_rezerwacje;}
        void setAktywne_rezerwacje(std::vector<Rezerwacja> val) {aktywne_rezerwacje = val;}

        void menu();
        bool zarezerwuj(int id_klient, const Pojazd& pojazd, const Date& data, int okres, const std::string metoda);
        void dodajPojazd(int id_pracownik, const Pojazd& pojazd);
        bool usunPojazd(int id_pracownik, const std::string& numer_vin);
        void zatwierdzRezerwacje(int id_pracownik, int id_klient, const Rezerwacja& rezerwacja);
        bool zamknijRezerwacje(int id_pracownik, int id_klient, const Rezerwacja& rezerwacja);
        void naliczKare(int id_pracownik, int id_klient, double kwota);
};

#endif // SYSTEMREZERWACJI_HPP
