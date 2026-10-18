#ifndef PLATNOSC_HPP
#define PLATNOSC_HPP

#include <string>

class Platnosc
{
    private:
        std::string metoda;
        double koszt;

    public:
        Platnosc(const std::string& metoda="", double koszt=0.0)
        : metoda(metoda), koszt(koszt) {}
        virtual ~Platnosc();

        const std::string& getMetoda() const;
        void setMetoda(const std::string& val);
        double getKoszt() const;
        void setKoszt(double val);
};

#endif // PLATNOSC_HPP
