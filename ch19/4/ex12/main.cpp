#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

class Screen
{
    friend int main();

public:
    typedef std::string::size_type pos;

    char get_cursor() const { return contents[cursor]; }
    char get() const { return contents[cursor]; }
    char get(pos ht, pos wd) const;

    static const std::string Screen::*data()
    { return &Screen::contents; }

private:
    std::string contents;
    pos cursor = 0;
    pos height = 0, width = 0;
};

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

int main()
{
    Screen::pos Screen::*pcursor = &Screen::cursor;
    Screen screen;
    std::cout << screen.*pcursor << std::endl;
    return 0;
}
