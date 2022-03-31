#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include <vector>
//#include "Screen.h"

template <unsigned H, unsigned W> class Screen;

template <unsigned H, unsigned W>
class Window_mgr
{
public:
    using ScreenIndex = typename std::vector<Screen<W, H>>::size_type;
    void clear(ScreenIndex);

    ScreenIndex addScreen(const Screen<H, W> &);

private:
    //std::vector<Screen> screens{Screen(24, 80, ' ')};
    std::vector<Screen<H, W>> screens;
};
#endif
