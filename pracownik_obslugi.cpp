#include "pracownik_obslugi.hpp"

int PracownikObslugi::getId_pracownik() const
{
    return id_pracownik;
}

const Date& PracownikObslugi::getData_zatrudnienia() const
{
    return data_zatrudnienia;
}

double PracownikObslugi::getPensja() const
{
    return pensja;
}

void PracownikObslugi::setId_pracownik(int val)
{
    id_pracownik=val;
}

void PracownikObslugi::setData_zatrudnienia(const Date& val)
{
    data_zatrudnienia=val;
}

void PracownikObslugi::setPensja(double val)
{
    pensja=val;
}