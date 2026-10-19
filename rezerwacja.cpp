#include "rezerwacja.hpp"

const Date& Rezerwacja::getData_rezerwacji() const
{
    return data_rezerwacji;
}

const Date& Rezerwacja::getData_zwrotu() const
{
    return data_zwrotu;
}

const std::vector<PozycjaRezerwacji>& Rezerwacja::getPozycje() const
{
    return pozycje;
}

const Platnosc& Rezerwacja::getPlatnosc() const
{
    return platnosc;
}

bool Rezerwacja::getPotwierdzenie() const
{
    return potwierdzenie;
}

void Rezerwacja::setData_rezerwacji(const Date& val)
{
    data_rezerwacji=val;
}

void Rezerwacja::setData_zwrotu(const Date& val)
{
    data_zwrotu=val;
}

void Rezerwacja::setPozycje(const std::vector<PozycjaRezerwacji>& val)
{
    pozycje=val;
}

void Rezerwacja::setPlatnosc(const Platnosc& val)
{
    platnosc=val;
}

void Rezerwacja::setPotwierdzenie(bool val)
{
    potwierdzenie=val;
}