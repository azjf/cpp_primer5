#include "Screen.h"

Screen::pos Screen::size() const
{
    return height * width;
}

void Screen::some_member() const
{
    ++access_ctr;
}
