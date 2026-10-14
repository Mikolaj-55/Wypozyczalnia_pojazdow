#ifndef PLATNOSC_HPP
#define PLATNOSC_HPP


class Platnosc
{
    public:
        Platnosc(std::string metoda, double koszt);
        virtual ~Platnosc();

        std::string Getmetoda() { return metoda; }
        void Setmetoda(std::string val) { metoda = val; }
        double Getkoszt() { return koszt; }
        void Setkoszt(double val) { koszt = val; }

    protected:

    private:
        std::string metoda;
        double koszt;
};

#endif // PLATNOSC_HPP
