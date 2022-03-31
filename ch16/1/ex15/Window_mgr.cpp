#include <string>
#include "Window_mgr.h"
#include "Screen.h"

template <unsigned H, unsigned W>
void Window_mgr<H, W>::clear(ScreenIndex i)
{
    Screen<H, W> &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

template <unsigned H, unsigned W>
typename Window_mgr<H, W>::ScreenIndex
Window_mgr<H, W>::addScreen(const Screen<H, W> &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}
