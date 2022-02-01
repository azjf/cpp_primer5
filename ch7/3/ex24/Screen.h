#ifndef SCREEN_H
#define SCREEN_H
#include <string>

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
    bool move(pos row, pos col);

private:
    pos cursor = 0;
    pos width = 0, height = 0;
    std::string contents;
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
bool Screen::move(pos row, pos col)
{
    if (row > width || col > height) {
        return false;
    }
    cursor = row * width + col - 1;
    return true;
}
#endif
