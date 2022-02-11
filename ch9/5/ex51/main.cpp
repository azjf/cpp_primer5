#include <iostream>
#include "Date.h"

int main()
{
    Date date1("January 1, 1900");
    std::cout << date1.get_year() << " " << date1.get_month()
        << " " << date1.get_day() << std::endl;

    Date date2("1/1/1900");
    std::cout << date2.get_year() << " " << date2.get_month()
        << " " << date2.get_day() << std::endl;

    Date date3("Jan 1 1900");
    std::cout << date3.get_year() << " " << date3.get_month()
        << " " << date3.get_day() << std::endl;
    return 0;
}
