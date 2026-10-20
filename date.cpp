#include <iostream>
#include "date.hpp"

Date::Date(int day, int month, int year)
    : day(day), month(month), year(year) {}

Date::~Date() = default;


int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

void Date::setDay(int val)
{
    day=val;
}

void Date::setMonth(int val)
{
    month=val;
}

void Date::setYear(int val)
{
    year=val;
}


void Date::print(int day, int month, int year) const
{
    std::cout<<day<<"."<<month<<"."<<year<<'\n';
}