#include "platnosc.hpp"

Platnosc::Platnosc(const std::string& metoda, double koszt)
    : metoda(metoda), koszt(koszt) {}

Platnosc::~Platnosc() = default;


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