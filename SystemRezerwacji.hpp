#ifndef SYSTEMREZERWACJI_HPP
#define SYSTEMREZERWACJI_HPP

#include "PracownikObslugi.hpp"
#include "Klient.hpp"
#include "Pojazd.hpp"
#include "Rezerwacja.hpp"

class SystemRezerwacji
{
    public:
        SystemRezerwacji(double stawkaDniowa, std::vector<PracownikObslugi> listaPracownikow, std::vector<Klient> listaKlientow, std::vector<Pojazd> katalogPojazdow, std::vector<Rezerwacja> aktywneRezerwacje);
        virtual ~SystemRezerwacji();

        double GetstawkaDniowa() { return stawkaDniowa; }
        void SetstawkaDniowa(double val) { stawkaDniowa = val; }
        std::vector<PracownikObslugi> GetlistaPracownikow() { return listaPracownikow; }
        void SetlistaPracownikow(std::vector<PracownikObslugi> val) { listaPracownikow = val; }
        std::vector<Klient> GetlistaKlientow() { return listaKlientow; }
        void SetlistaKlientow(std::vector<Klient> val) { listaKlientow = val; }
        std::vector<Rezerwacja> GetaktywneRezerwacje() { return aktywneRezerwacje; }
        void SetaktywneRezerwacje(std::vector<Rezerwacja> val) { aktywneRezerwacje = val; }

        void menu();
        bool zarezerwuj(int id_klient, const Pojazd& pojazd, const Date& data, int okres, const std::string metoda);
        void dodajPojazd(int id_Pracownik, const Pojazd& pojazd);
        bool usunPojazd(int id_Pracownik, const std::string& VIN);
        void zatwierdzRezerwacje(int id_Pracownik, int id_klient, const Rezerwacja& rezerwacja);
        bool zamknijRezerwacje(int id_Pracownik, int id_klient, const Rezerwacja& rezerwacja);
        void naliczKare(int id_Pracownik, int id_klient, double kwota);

    protected:

    private:
        double stawkaDniowa;
        std::vector<PracownikObslugi> listaPracownikow;
        std::vector<Klient> listaKlientow;
        std::vector<Rezerwacja> aktywneRezerwacje;
};

#endif // SYSTEMREZERWACJI_HPP
