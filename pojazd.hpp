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
        Pojazd(const std::string& marka="", const std::string& model="", const std::string& typ="", const std::string& numer_vin="", bool dostepnosc=false);
        virtual ~Pojazd();

        const std::string& getMarka() const;
        void setMarka(const std::string& val);
        const std::string& getModel() const;
        void setModel(const std::string& val);
        const std::string& getTyp() const;
        void setTyp(const std::string& val);
        const std::string& getNumer_vin() const;
        void setNumer_vin(const std::string& val);
        bool getDostepnosc() const;
        void setDostepnosc(bool val);
};

#endif // POJAZD_HPP
