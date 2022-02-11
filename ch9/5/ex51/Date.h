#ifndef DATE_H
#define DATE_H
#include <string>

class Date
{
public:
    Date() = default;
    Date(std::string s);
    unsigned get_year() { return year; }
    unsigned get_month() { return month; }
    unsigned get_day() { return day; }

private:
    unsigned year = 0, month = 0, day = 0;
};
#endif
