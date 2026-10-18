#ifndef DATE_HPP
#define DATE_HPP


class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int day, int month, int year)
        : day(day), month(month), year(year) {}
        virtual ~Date();

        int getDay() const;
        void setDay(int val);
        int getMonth() const;
        void setMonth(int val);
        int getYear() const;
        void setYear(int val);

        //jakis print jeszcze
};

#endif // DATE_HPP
