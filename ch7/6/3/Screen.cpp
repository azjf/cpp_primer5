#include "Screen.h"

int height;

void Screen::some_member() const
{
    ++access_ctr;
}

void Screen::dummy_fcn2(pos height)
{
    cursor = width * this->height;
    cursor = width * Screen::height;
}

void Screen::dummy_fcn3(pos ht)
{
    cursor = width * height;
    cursor = width * ::height;
}

Screen::pos verify(Screen::pos pos)
{
    return 0;
}

void Screen::setHeight(pos var)
{
    height = verify(var);
}
