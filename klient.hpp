#ifndef KLIENT_HPP
#define KLIENT_HPP

#include <vector>
#include "osoba.hpp"
#include "rezerwacja.hpp"


class Klient : public Osoba
{
    private:
        std::vector<Rezerwacja> lista_rezerwacji;
        double kary;

    public:
        Klient(std::vector<Rezerwacja>& lista_rezerwacji={}, double kary=0.0)
        : lista_rezerwacji(lista_rezerwacji), kary(kary) {}
        virtual ~Klient() = default;

        void dodajRezerwacje(const Rezerwacja& rezerwacja);
        bool usunRezerwacje(const Rezerwacja& rezerwacja);
        void dodajKare(double kara);

        std::vector<Rezerwacja>& getLista_rezerwacji() const{return lista_rezerwacji;}
        double getKary() const{return kary;}
};

#endif // KLIENT_HPP
