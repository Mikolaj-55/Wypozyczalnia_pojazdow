#ifndef DATE_HPP
#define DATE_HPP


class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int day, int month, int year);
        virtual ~Date();

        int getDay() {return day;}
        void setDay(int val) {day = val;}
        int getMonth() {return month;}
        void setMonth(int val) {month = val;}
        int getYear() {return year;}
        void setYear(int val) {year = val;}
};

#endif // DATE_HPP
