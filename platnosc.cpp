#include "platnosc.hpp"

const std::string& Platnosc::getMetoda() const
{
    return metoda;
}

double Platnosc::getKoszt() const
{
    return koszt;
}

void Platnosc::setMetoda(const std::string& val)
{
    metoda=val;
}

void Platnosc::setKoszt(double val)
{
    koszt=val;
}