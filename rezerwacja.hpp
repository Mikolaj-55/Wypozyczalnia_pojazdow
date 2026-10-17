#ifndef REZERWACJA_HPP
#define REZERWACJA_HPP

#include "date.hpp"
#include "pozycja_rezerwacji.hpp"
#include "platnosc.hpp"

class Rezerwacja
{
    private:
        Date data_rezerwacji;
        Date data_zwrotu;
        std::vector<PozycjaRezerwacji> pozycje;
        Platnosc platnosc;
        bool potwierdzenie;

    public:
        Rezerwacja(Date data_rezerwacji, Date data_zwrotu, std::vector<PozycjaRezerwacji> pozycje, Platnosc platnosc, bool potwierdzenie);
        virtual ~Rezerwacja();

        Date getData_rezerwacji() {return data_rezerwacji;}
        void setData_rezerwacji(Date val) {data_rezerwacji = val;}
        Date getData_zwrotu() {return data_zwrotu;}
        void setData_zwrotu(Date val) {data_zwrotu = val;}
        std::vector<PozycjaRezerwacji> getPozycje() {return pozycje;}
        void setPozycje(std::vector<PozycjaRezerwacji> val) {pozycje = val;}
        Platnosc getPlatnosc() {return platnosc;}
        void setPlatnosc(Platnosc val) {platnosc = val;}
        bool getPotwierdzenie() {return potwierdzenie;}
        void setPotwierdzenie(bool val) {potwierdzenie = val;}
};

#endif // REZERWACJA_HPP
