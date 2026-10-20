#include "pozycja_rezerwacji.hpp"

PozycjaRezerwacji::PozycjaRezerwacji(const Pojazd& pojazd)
    : pojazd(pojazd) {}

PozycjaRezerwacji::~PozycjaRezerwacji() = default;


const Pojazd& PozycjaRezerwacji::getPojazd() const
{
    return pojazd;
}

void PozycjaRezerwacji::setPojazd(const Pojazd& val)
{
    pojazd=val;
}