#ifndef DATE_HPP
#define DATE_HPP


class Date
{
    public:
        Date(int day, int month, int year);
        virtual ~Date();

        int Getday() { return day; }
        void Setday(int val) { day = val; }
        int Getmonth() { return month; }
        void Setmonth(int val) { month = val; }
        int Getyear() { return year; }
        void Setyear(int val) { year = val; }

    protected:

    private:
        int day;
        int month;
        int year;
};

#endif // DATE_HPP
