#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>

class Screen
{
public:
    typedef std::string::size_type pos;

    Screen() = default;
    Screen(pos wd, pos ht) :
        width(wd), height(ht), contents(wd * ht, ' ') { }
    Screen(pos wd, pos ht, char c) :
        width(wd), height(ht), contents(wd * ht, c) { }

    char get() const;
    char get(pos row, pos col) const;

    Screen &move(pos row, pos col);
    Screen &set(char ch);
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }

private:
    pos cursor = 0;
    pos width = 0, height = 0;
    std::string contents;

    void do_display(std::ostream &os) const { os << contents; }
};

inline
char Screen::get() const
{
    if (cursor >= contents.size()) {
        return -1;
    }
    return contents[cursor];
}

inline
char Screen::get(pos row, pos col) const
{
    if (row > width || col > height) {
        return -1;
    }
    return contents[row * width + col - 1];
}

inline
Screen &Screen::move(pos row, pos col)
{
    cursor = row * width + col - 1;
    return *this;
}

inline
Screen &Screen::set(char ch)
{
    contents[cursor] = ch;
    return *this;
}
#endif
