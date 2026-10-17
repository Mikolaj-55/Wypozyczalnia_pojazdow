#ifndef PLATNOSC_HPP
#define PLATNOSC_HPP


class Platnosc
{
    private:
        std::string metoda;
        double koszt;

    public:
        Platnosc(std::string metoda, double koszt);
        virtual ~Platnosc();

        std::string getMetoda() {return metoda;}
        void setMetoda(std::string val) {metoda = val;}
        double getKoszt() {return koszt;}
        void setKoszt(double val) {koszt = val;}
};

#endif // PLATNOSC_HPP
