#include "klient.hpp"

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