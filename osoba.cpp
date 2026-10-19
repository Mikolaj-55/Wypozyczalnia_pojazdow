#include "osoba.hpp"

const std::string& Osoba::getImie() const
{
    return imie;
}

const std::string& Osoba::getNazwisko() const
{
    return nazwisko;
}

int Osoba::getId() const
{
    return id;
}

void Osoba::setImie(const std::string& val)
{
    imie=val;
}

void Osoba::setNazwisko(const std::string& val)
{
    nazwisko=val;
}

void Osoba::setId(int val)
{
    id=val;
}