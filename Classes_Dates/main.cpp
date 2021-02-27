//Author: Peter Ngure
//Date: 2021
#include <iostream>
#include <iomanip>

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date(int d=1, int m=1, int y=1970); //normal constructor
    explicit Date(const Date& d); // copy constructors
    void setDate(int d, int m, int y);
    void checkDate();
    void setDay(int day);
    Date& incDay();
    static inline const int daysPerMonth[]{31,28,31,30,31,30,31,31,30,31,30,31};
    static const int stdYear{1970};
    int getDay() const {return day;}
    int getMonth() const {return month;}
    int getYear() const {return year;}
    Date& operator ++();
    void print() const;

};
Date::Date(int d, int m, int y)
{
    day=d;month=m;year=y;
}
Date::Date(const Date& d):day{d.day},month{d.month},year{d.year}{}
void Date::setDate(int d, int m, int y)
{
    day=d;
    month = m;
    year = y;
}
void Date::setDay(int day)
{
    this -> day = day;
}
bool isLeapYear(int year)
{
    return ((year%4==0 && year%100 != 0)|| year%400==0);
}
void Date::checkDate() {
    if (year<1||month<1||day<1||(day>daysPerMonth[month-1]&&
    !(day == 29 && month==2 && month ==2 && isLeapYear(year))))
    {
    day=month=1;
    year=stdYear;
    }
}

Date& Date::incDay() {
    ++day;
    if(day>daysPerMonth[month-1] && !(day==29 && month ==2 && isLeapYear(year)))
    {
        day=1;
        if (++month==13)
        {
            month = 1;
            ++year;
        }
    }
    return *this;
}

Date& Date::operator++() {
    incDay();
    return *this;
}
std::ostream& operator <<(std::ostream& os, Date& d)
{
    os<<d.getDay()<<"."<<d.getMonth()<<"."<<d.getYear()<<std::endl;
    return os;
}

void Date::print() const
{
    std::cout<<day<<"."<<month<<"."<<year<<std::endl;
}
int main() {
    Date d1;
    d1.print();
    d1.setDate(3,4,1960);
    d1.print();
    Date d2(30,12,2020);
    d2.incDay().incDay().incDay();
    d2.print();
    Date d4(d2);
    (++d4).print();
    std::cout<<"Day = "<<d2.getDay()<<std::endl;
    d4.print();

    return 0;
}
