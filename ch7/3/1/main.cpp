#include <iostream>
#include "Screen.h"
#include "Link_screen.h"

int main()
{
    Screen myscreen(24, 80, ' ');
    char ch = myscreen.get();
    ch = myscreen.get(0, 0);

    myscreen.move(4, 0).set('#');

    Screen myScreen(5, 3);
    const Screen blank(5, 3);
    myScreen.set('#').display(std::cout);
    blank.display(std::cout);

    Link_screen link_screen;
    return 0;
}
