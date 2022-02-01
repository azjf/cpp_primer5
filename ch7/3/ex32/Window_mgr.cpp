#include <string>
#include "Window_mgr.h"
#include "Screen.h"


void Window_mgr::clear(ScreenIndex si)
{
    Screen &s = screens[si];
    s.contents = std::string(s.width * s.height, ' ');
}
