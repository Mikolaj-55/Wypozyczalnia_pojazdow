#ifndef OSOBA_HPP
#define OSOBA_HPP

#include <string>


class Osoba
{
    protected:
        std::string imie;
        std::string nazwisko;
        int id;

    public:
        Osoba(std::string imie="", std::string nazwisko="", int id=0)
        : imie(imie), nazwisko(nazwisko), id(id) {}

        virtual ~Osoba() = default;

        std::string getImie() const{return imie;}
        void setImie(const std::string& val){imie=val;}

        std::string getNazwisko() const {return nazwisko;}
        void setNazwisko(const std::string& val){nazwisko=val;}

        int getId() const{return id;}
        void setId(int val){id=val;}
};

#endif // OSOBA_HPP
