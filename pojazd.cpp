#include "pojazd.hpp"

Pojazd::Pojazd(const std::string& marka, const std::string& model, const std::string& typ, const std::string& numer_vin, bool dostepnosc)
    : marka(marka), model(model), typ(typ), numer_vin(numer_vin), dostepnosc(dostepnosc) {}

Pojazd::~Pojazd() = default;


const std::string& Pojazd::getMarka() const
{
    return marka;
}

const std::string& Pojazd::getModel() const
{
    return model;
}

const std::string& Pojazd::getTyp() const
{
    return typ;
}

const std::string& Pojazd::getNumer_vin() const
{
    return numer_vin;
}

bool Pojazd::getDostepnosc() const
{
    return dostepnosc;
}

void Pojazd::setMarka(const std::string& val)
{
    marka=val;
}

void Pojazd::setModel(const std::string& val)
{
    model=val;
}

void Pojazd::setTyp(const std::string& val)
{
    typ=val;
}

void Pojazd::setNumer_vin(const std::string& val)
{
    numer_vin=val;
}

void Pojazd::setDostepnosc(bool val)
{
    dostepnosc=val;
}