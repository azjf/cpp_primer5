#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>
#include <algorithm>
#include "Window_mgr.h"

template <unsigned H, unsigned W> class Window_mgr;
template <unsigned H, unsigned W> class Screen;

template <unsigned H, unsigned W> std::istream
&operator>>(std::istream &is, Screen<H, W> &);

template <unsigned H, unsigned W> std::ostream
&operator<<(std::ostream &os, const Screen<H, W> &);

template <unsigned H, unsigned W>
class Screen
{
    friend class Window_mgr<H, W>;
    friend void Window_mgr<H, W>::clear(typename Window_mgr<H, W>::ScreenIndex);
    friend std::istream &operator>><H, W>(std::istream &is, Screen &);
    //friend std::ostream &operator<<<H, W>(std::ostream &os, const Screen &);

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

    Screen &clear(char = bkground)
        { contents = std::string(height * width, bkground); return *this; }

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
const char Screen<H, W>::bkground = ' ';

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

template <unsigned H, unsigned W> std::istream
&operator>>(std::istream &is, Screen<H, W> &screen)
{
    screen.clear();
    std::string line;
    unsigned line_no = 0;
    while (std::getline(is, line)) {
        auto out_it = screen.contents.begin() + screen.width * line_no;
        std::copy_n(line.cbegin(), std::min(screen.width, line.size()), out_it);
        if (++line_no >= screen.height) {
            break;
        }
    }
    return is;
}

template <unsigned H, unsigned W> std::ostream
&operator<<(std::ostream &os, const Screen<H, W> &screen)
{
    //screen.do_display(os);
    screen.display(os);
    return os;
}
#endif
