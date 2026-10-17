#ifndef POJAZD_HPP
#define POJAZD_HPP

#include <string>

class Pojazd
{
    private:
        std::string marka;
        std::string model;
        std::string typ;
        std::string numer_vin;
        bool dostepnosc;

    public:
        Pojazd(std::string marka, std::string model, std::string typ, std::string numer_vin, bool dostepnosc);
        virtual ~Pojazd();

        std::string getMarka() {return marka;}
        void setMarka(std::string val) {marka = val;}
        std::string getModel() {return model;}
        void setModel(std::string val) {model = val;}
        std::string getTyp() {return typ;}
        void setTyp(std::string val) {typ = val;}
        std::string getNumer_vin() {return numer_vin;}
        void setNumer_vin(std::string val) {numer_vin = val;}
        bool getDostepnosc() {return dostepnosc;}
        void setDostepnosc(bool val) {dostepnosc = val;}
};

#endif // POJAZD_HPP
