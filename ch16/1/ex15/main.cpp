#include <iostream>
#include "Screen.h"
#include "Link_screen.h"

int main()
{
    //Screen::pos ht = 24, wd = 80;
    unsigned ht = 24, wd = 80;
    Screen<24, 80> scr(ht, wd, ' ');

    std::cin >> scr;
    std::cout << scr << std::endl;
    return 0;
}
