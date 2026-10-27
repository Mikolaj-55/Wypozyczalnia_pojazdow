#ifndef KLIENT_HPP
#define KLIENT_HPP

#include <string>
#include <vector>
#include "osoba.hpp"
#include "rezerwacja.hpp"


class Klient : public Osoba
{
    private:
        std::vector<Rezerwacja> lista_rezerwacji;
        double kary;

    public:
        Klient(const std::string& imie = "", const std::string& nazwisko = "", int id = 0, const std::vector<Rezerwacja>& lista_rezerwacji={}, double kary=0.0);
        virtual ~Klient();

        const std::vector<Rezerwacja>& getLista_rezerwacji() const;
        void setLista_rezerwacji(const std::vector<Rezerwacja>& val);
        double getKary() const;
        void setKary(double val);
        
        void dodajRezerwacje(const Rezerwacja& rezerwacja);
        bool usunRezerwacje(int id_rezerwacji);
        void dodajKare(double kara);

};

#endif // KLIENT_HPP
