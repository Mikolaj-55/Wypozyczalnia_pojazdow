#ifndef PRACOWNIKOBSLUGI_HPP
#define PRACOWNIKOBSLUGI_HPP

#include "Osoba.hpp"
//#include "Date.hpp"

class PracownikObslugi : public Osoba
{
    private:
        int idPracownik;
        Date dataZatrudnienia;
        double pensja;

    public:
        PracownikObslugi(int idPracownik=0, Date dataZatrudnienia=Date(), double pensja=0.0)
        : idPracownik(idPracownik), dataZatrudnienia(dataZatrudnienia), pensja(pensja) {}
        virtual ~PracownikObslugi() = default;

        int GetidPracownik() const{ return idPracownik; }
        void SetidPracownik(int val) { idPracownik = val; }

        Date& GetdataZatrudnienia() const{ return dataZatrudnienia; }
        void SetdataZatrudnienia(Date& val) { dataZatrudnienia = val; }

        double Getpensja() const{ return pensja; }
        void Setpensja(double val) { pensja = val; }

};

#endif // PRACOWNIKOBSLUGI_HPP
