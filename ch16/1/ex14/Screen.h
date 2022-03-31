#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>
#include "Window_mgr.h"

template <unsigned H, unsigned W> class Window_mgr;

template <unsigned H, unsigned W>
class Screen
{
    friend class Window_mgr<H, W>;
    friend void Window_mgr<H, W>::clear(typename Window_mgr<H, W>::ScreenIndex);

public:
    typedef std::string::size_type pos;
    //using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd, char c = ' ') :
        height(ht), width(wd), contents(ht * wd, c) { }

    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);

    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const
        { do_display(os); return *this; }

    Screen &clear(char = bkground);

    void setHeight(pos);

private:
    pos cursor = 0;
    pos height = H, width = W;
    std::string contents;

    mutable size_t access_ctr;

    static const char bkground;

    void do_display(std::ostream &os) const { os << contents; }
};

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

template <unsigned H, unsigned W>
char Screen<H, W>::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::set(char c)
{
    contents[cursor] = c;
    return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}
#endif
