#include "klient.hpp"

Klient::Klient(const std::string& imie, const std::string& nazwisko, int id, const std::vector<Rezerwacja>& lista_rezerwacji, double kary)
    : Osoba(imie, nazwisko, id), lista_rezerwacji(lista_rezerwacji), kary(kary) {}

Klient::~Klient() = default;


const std::vector<Rezerwacja>& Klient::getLista_rezerwacji() const
{
    return lista_rezerwacji;
}

double Klient::getKary() const
{
    return kary;
}

void Klient::setLista_rezerwacji(const std::vector<Rezerwacja>& val)
{
    lista_rezerwacji=val;
}

void Klient::setKary(double val)
{
    kary=val;
}


void Klient::dodajRezerwacje(const Rezerwacja& rezerwacja)
{

}

bool Klient::usunRezerwacje(const Rezerwacja& rezerwacja)
{

}

void Klient::dodajKare(double kara)
{

}