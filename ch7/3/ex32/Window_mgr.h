#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include <vector>

class Screen;

class Window_mgr
{
public:
    typedef std::vector<Screen>::size_type ScreenIndex;
    void clear(ScreenIndex si);

private:
    std::vector<Screen> screens;
};
#endif
