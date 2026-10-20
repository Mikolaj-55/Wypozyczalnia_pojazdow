#include "rezerwacja.hpp"

Rezerwacja::Rezerwacja(const Date& data_rezerwacji, const Date& data_zwrotu, const std::vector<PozycjaRezerwacji>& pozycje, const Platnosc& platnosc, bool potwierdzenie)
    : data_rezerwacji(data_rezerwacji), data_zwrotu(data_zwrotu), pozycje(pozycje), platnosc(platnosc), potwierdzenie(potwierdzenie) {}

Rezerwacja::~Rezerwacja() = default;


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