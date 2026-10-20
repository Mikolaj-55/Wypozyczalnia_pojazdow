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
        Osoba(const std::string& imie="", const std::string& nazwisko="", int id=0);
        virtual ~Osoba();

        const std::string& getImie() const;
        void setImie(const std::string& val);
        const std::string& getNazwisko() const;
        void setNazwisko(const std::string& val);
        int getId() const;
        void setId(int val);
};

#endif // OSOBA_HPP
