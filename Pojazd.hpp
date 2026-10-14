#ifndef POJAZD_HPP
#define POJAZD_HPP

#include <string>

class Pojazd
{
    public:
        Pojazd(std::string marka, std::string model, std::string typ, std::string numerVIN, bool dostepnosc);
        virtual ~Pojazd();

        std::string Getmarka() { return marka; }
        void Setmarka(std::string val) { marka = val; }
        std::string Getmodel() { return model; }
        void Setmodel(std::string val) { model = val; }
        std::string Gettyp() { return typ; }
        void Settyp(std::string val) { typ = val; }
        std::string GetnumerVIN() { return numerVIN; }
        void SetnumerVIN(std::string val) { numerVIN = val; }
        bool Getdostepnosc() { return dostepnosc; }
        void Setdostepnosc(bool val) { dostepnosc = val; }

    protected:

    private:
        std::string marka;
        std::string model;
        std::string typ;
        std::string numerVIN;
        bool dostepnosc;
};

#endif // POJAZD_HPP
