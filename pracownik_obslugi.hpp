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
        PracownikObslugi(int id_pracownik=0, Date data_zatrudnienia=Date(), double pensja=0.0)
        : id_pracownik(id_pracownik), data_zatrudnienia(data_zatrudnienia), pensja(pensja) {}
        virtual ~PracownikObslugi() = default;

        int getId_pracownik() const{return id_pracownik;}
        void setId_pracownik(int val) {id_pracownik = val;}
        Date& getData_zatrudnienia() const{return data_zatrudnienia;}
        void setData_zatrudnienia(Date& val) {data_zatrudnienia = val;}
        double getPensja() const{return pensja;}
        void setPensja(double val) {pensja = val;}

};

#endif // PRACOWNIKOBSLUGI_HPP
