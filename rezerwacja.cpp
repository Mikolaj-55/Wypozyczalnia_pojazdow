#include <iostream>
#include "rezerwacja.hpp"
using namespace std;

Rezerwacja::Rezerwacja(int id_rezerwacji, const Date& data_rezerwacji, const Date& data_zwrotu, const std::vector<PozycjaRezerwacji>& pozycje, const Platnosc& platnosc, bool potwierdzenie)
    : id_rezerwacji(id_rezerwacji), data_rezerwacji(data_rezerwacji), data_zwrotu(data_zwrotu), pozycje(pozycje), platnosc(platnosc), potwierdzenie(potwierdzenie) {}

Rezerwacja::~Rezerwacja() = default;

int Rezerwacja::getId_rezerwacji() const
{
    return id_rezerwacji;
}

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

void Rezerwacja::setId_rezerwacji(int val)
{
    id_rezerwacji=val;
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


void Rezerwacja::print() const
{
    cout<<"ID rezerwacji: "<<id_rezerwacji<<endl<<"Data rezerwacji: ";
    data_rezerwacji.print();
    cout<<endl<<"Data zwrotu: ";
    data_zwrotu.print();
    cout<<endl<<"Pozycje:";
    for(const auto& x : pozycje){
        std::cout<<std::endl<<endl;
        x.getPojazd().print();
    }
    cout<<endl<<endl<<"Platnosc:"<<endl;
    platnosc.print();
    cout<<endl<<endl<<"Potwierdzenie rezerwacji: "<<potwierdzenie;

}
