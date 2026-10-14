#ifndef REZERWACJA_HPP
#define REZERWACJA_HPP

#include "Date.hpp"
#include "PozycjaRezerwacji.hpp"
#include "Platnosc.hpp"

class Rezerwacja
{
    public:
        Rezerwacja(Date dataRezerwacji, Date dataZwrotu, std::vector<PozycjaRezerwacji> pozycje, Platnosc platnosc, bool potwierdzenie);
        virtual ~Rezerwacja();

        Date GetdataRezerwacji() { return dataRezerwacji; }
        void SetdataRezerwacji(Date val) { dataRezerwacji = val; }
        Date GetdataZwrotu() { return dataZwrotu; }
        void SetdataZwrotu(Date val) { dataZwrotu = val; }
        std::vector<PozycjaRezerwacji> Getpozycje() { return pozycje; }
        void Setpozycje(std::vector<PozycjaRezerwacji> val) { pozycje = val; }
        Platnosc Getplatnosc() { return platnosc; }
        void Setplatnosc(Platnosc val) { platnosc = val; }
        bool Getpotwierdzenie() { return potwierdzenie; }
        void Setpotwierdzenie(bool val) { potwierdzenie = val; }

    protected:

    private:
        Date dataRezerwacji;
        Date dataZwrotu;
        std::vector<PozycjaRezerwacji> pozycje;
        Platnosc platnosc;
        bool potwierdzenie;
};

#endif // REZERWACJA_HPP
