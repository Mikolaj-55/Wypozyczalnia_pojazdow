#ifndef PRACOWNIKOBSLUGI_HPP
#define PRACOWNIKOBSLUGI_HPP

#include <string>
#include "osoba.hpp"
#include "date.hpp"

class PracownikObslugi : public Osoba
{
    private:
        Date data_zatrudnienia;
        double pensja;

    public:
        PracownikObslugi(const std::string& imie = "", const std::string& nazwisko = "", int id = 0, const Date& data_zatrudnienia=Date(), double pensja=0.0);
        virtual ~PracownikObslugi();

        const Date& getData_zatrudnienia() const;
        void setData_zatrudnienia(const Date& val);
        double getPensja() const;
        void setPensja(double val);

};

#endif // PRACOWNIKOBSLUGI_HPP
