#ifndef POZYCJAREZERWACJI_HPP
#define POZYCJAREZERWACJI_HPP

#include "pojazd.hpp"

class PozycjaRezerwacji
{
    private:
        Pojazd pojazd;

    public:
        PozycjaRezerwacji(const Pojazd& pojazd=Pojazd())
        : pojazd(pojazd) {}
        virtual ~PozycjaRezerwacji()=default;

        const Pojazd& getPojazd() const;
        void setPojazd(const Pojazd& val);
};

#endif // POZYCJAREZERWACJI_HPP
