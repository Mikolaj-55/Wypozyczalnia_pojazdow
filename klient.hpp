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
        Klient(const std::vector<Rezerwacja>& lista_rezerwacji={}, double kary=0.0)
        : lista_rezerwacji(lista_rezerwacji), kary(kary) {}
        virtual ~Klient() = default;

        const std::vector<Rezerwacja>& getLista_rezerwacji() const;
        void setLista_rezerwacji(const std::vector<Rezerwacja>& val);
        double getKary() const;
        void setKary(double val);
        
        void dodajRezerwacje(const Rezerwacja& rezerwacja);
        bool usunRezerwacje(const Rezerwacja& rezerwacja);
        void dodajKare(double kara);

};

#endif // KLIENT_HPP
