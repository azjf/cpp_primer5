#include <iostream>
#include "Screen.h"
#include "Link_screen.h"

int main()
{
    Screen::pos ht = 24, wd = 80;
    Screen scr(ht, wd, ' ');
    Screen *p = &scr;
    char c = scr.get();
    c = p->get();
    return 0;
}
