#ifndef SYSTEMREZERWACJI_HPP
#define SYSTEMREZERWACJI_HPP

#include <string>
#include <vector>
#include "pracownik_obslugi.hpp"
#include "klient.hpp"
#include "pojazd.hpp"
#include "rezerwacja.hpp"
#include "date.hpp"

class SystemRezerwacji
{
    private:
        double stawka_dniowa;
        std::vector<PracownikObslugi> lista_pracownikow;
        std::vector<Klient> lista_klientow;
        std::vector<Pojazd> katalog_pojazdow;
        std::vector<Rezerwacja> aktywne_rezerwacje;

    public:
        SystemRezerwacji(double stawka_dniowa=0.0, const std::vector<PracownikObslugi>& lista_pracownikow={}, const std::vector<Klient>& lista_klientow={}, const std::vector<Pojazd>& katalog_pojazdow={}, const std::vector<Rezerwacja>& aktywne_rezerwacje={});
        virtual ~SystemRezerwacji();

        double getStawka_dniowa() const;
        void setStawka_dniowa(double val);
        const std::vector<PracownikObslugi>& getLista_pracownikow() const;
        void setLista_pracownikow(const std::vector<PracownikObslugi>& val);
        const std::vector<Klient>& getLista_klientow() const;
        void setLista_klientow(const std::vector<Klient>& val);
        const std::vector<Pojazd>& getKatalog_pojazdow() const;
        void setKatalog_pojazdow(const std::vector<Pojazd>& val);
        const std::vector<Rezerwacja>& getAktywne_rezerwacje() const;
        void setAktywne_rezerwacje(const std::vector<Rezerwacja>& val);

        Klient* znajdzKlienta(int id);
        bool czyPracownik(int id);
        void menuPracownik(int id_pracownik);
        void menuKlient(Klient klient);

        void menu();
        bool zarezerwuj(int id_klient, const Date& data, int okres, const std::string& metoda, PozycjaRezerwacji pojazd);
        void wybierzPojazd(const std::string &numer_vin, int id_pojazdu, bool pracownik, int osoba_id);
        void dodajPojazd(const Pojazd& pojazd);
        bool usunPojazd(const std::string& numer_vin);
        void zatwierdzRezerwacje(int id_pracownik, const Rezerwacja& rezerwacja);
        bool zamknijRezerwacje(int id_pracownik, int id_klient, const Rezerwacja& rezerwacja);
        void naliczKare(int id_pracownik, int id_klient, double kwota);
};

#endif // SYSTEMREZERWACJI_HPP
