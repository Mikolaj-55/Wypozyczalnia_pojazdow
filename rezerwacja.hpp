#ifndef REZERWACJA_HPP
#define REZERWACJA_HPP

#include <vector>
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
        Rezerwacja(const Date& data_rezerwacji=Date(), const Date& data_zwrotu=Date(), const std::vector<PozycjaRezerwacji>& pozycje={}, const Platnosc& platnosc=Platnosc(), bool potwierdzenie=false)
        : data_rezerwacji(data_rezerwacji), data_zwrotu(data_zwrotu), pozycje(pozycje), platnosc(platnosc), potwierdzenie(potwierdzenie) {}
        virtual ~Rezerwacja();

        const Date& getData_rezerwacji() const;
        void setData_rezerwacji(const Date& val);
        const Date& getData_zwrotu() const;
        void setData_zwrotu(const Date& val);
        const std::vector<PozycjaRezerwacji>& getPozycje() const;
        void setPozycje(const std::vector<PozycjaRezerwacji>& val);
        const Platnosc& getPlatnosc() const;
        void setPlatnosc(const Platnosc& val);
        bool getPotwierdzenie() const;
        void setPotwierdzenie(bool val);
};

#endif // REZERWACJA_HPP
