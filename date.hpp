#ifndef DATE_HPP
#define DATE_HPP


class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int day=0, int month=0, int year=0);
        virtual ~Date();

        int getDay() const;
        void setDay(int val);
        int getMonth() const;
        void setMonth(int val);
        int getYear() const;
        void setYear(int val);

        void print(int day, int month, int year) const;
};

#endif // DATE_HPP
