#include "pozycja_rezerwacji.hpp"

const Pojazd& PozycjaRezerwacji::getPojazd() const
{
    return pojazd;
}

void PozycjaRezerwacji::setPojazd(const Pojazd& val)
{
    pojazd=val;
}