#include "Screen.h"

template <unsigned H, unsigned W>
typename Screen<H, W>::pos verify(typename Screen<H, W>::pos pos)
{
    return 0;
}

template <unsigned H, unsigned W>
void Screen<H, W>::setHeight(pos var)
{
    height = verify<H, W>(var);
}
