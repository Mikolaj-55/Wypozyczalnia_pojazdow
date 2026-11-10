#include "pracownik_obslugi.hpp"

PracownikObslugi::PracownikObslugi(const std::string& imie, const std::string& nazwisko, int id, const Date& data_zatrudnienia, double pensja)
    : Osoba(imie, nazwisko, id), data_zatrudnienia(data_zatrudnienia), pensja(pensja) {}

PracownikObslugi::~PracownikObslugi() = default;


const Date& PracownikObslugi::getData_zatrudnienia() const
{
    return data_zatrudnienia;
}

double PracownikObslugi::getPensja() const
{
    return pensja;
}

void PracownikObslugi::setData_zatrudnienia(const Date& val)
{
    data_zatrudnienia=val;
}

void PracownikObslugi::setPensja(double val)
{
    pensja=val;
}