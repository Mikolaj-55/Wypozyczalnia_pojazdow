#ifndef PRACOWNIKOBSLUGI_HPP
#define PRACOWNIKOBSLUGI_HPP

#include "osoba.hpp"
#include "date.hpp"

class PracownikObslugi : public Osoba
{
    private:
        int id_pracownik;
        Date data_zatrudnienia;
        double pensja;

    public:
        PracownikObslugi(int id_pracownik=0, const Date& data_zatrudnienia=Date(), double pensja=0.0)
        : id_pracownik(id_pracownik), data_zatrudnienia(data_zatrudnienia), pensja(pensja) {}
        virtual ~PracownikObslugi() = default;

        int getId_pracownik() const;
        void setId_pracownik(int val);
        const Date& getData_zatrudnienia() const;
        void setData_zatrudnienia(const Date& val);
        double getPensja() const;
        void setPensja(double val);

};

#endif // PRACOWNIKOBSLUGI_HPP
