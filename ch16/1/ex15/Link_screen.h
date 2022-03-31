#ifndef LINK_SCREEN_H
#define LINK_SCREEN_H
#include "Screen.h"

template <unsigned H, unsigned W>
class Link_screen
{
    Screen<H, W> window;
    Link_screen *next;
    Link_screen *prev;
};
#endif
