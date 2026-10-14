#ifndef KLIENT_HPP
#define KLIENT_HPP

#include <vector>
#include "Osoba.hpp"
#include "Rezerwacja.hpp"


class Klient : public Osoba
{
    private:
        std::vector<Rezerwacja> listaRezerwacji;
        double kary;

    public:
        Klient(std::vector<Rezerwacja>& listaRezerwacji={}, double kary=0.0)
        : listaRezerwacji(listaRezerwacji), kary(kary) {}
        virtual ~Klient() = default;

        void dodajRezerwacje(const Rezerwacja& rezerwacja);
        bool usunRezerwacje(const Rezerwacja& rezerwacja);
        void dodajKare(double kara);

        std::vector<Rezerwacja>& getlistaRezerwacji() const{return listaRezerwacji;}
        double getKary() const{return kary;}
};

#endif // KLIENT_HPP
