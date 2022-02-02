#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include <vector>
//#include "Screen.h"

class Screen;

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

    ScreenIndex addScreen(const Screen &);

private:
    //std::vector<Screen> screens{Screen(24, 80, ' ')};
    std::vector<Screen> screens;
};
#endif
