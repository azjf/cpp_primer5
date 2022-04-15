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

    Screen &home() { return *this; }
    Screen &forward() { return *this; }
    Screen &back() { return *this; }
    Screen &up() { return *this; }
    Screen &down() { return *this; }

    using Action = Screen &(Screen::*)();
    enum Directions {HOME, FORWARD, BACK, UP, DOWN};
    Screen &move(Directions);

private:
    std::string contents;
    pos cursor = 0;
    pos height = 0, width = 0;

    static Action Menu[];
};

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

using Action = char (Screen::*)(Screen::pos, Screen::pos) const;
Screen &action(Screen &screen, Action = &Screen::get) { return screen; }

Screen &Screen::move(Directions cm)
{
    return (this->*Menu[cm])();
}

Screen::Action Screen::Menu[] = {&Screen::home, &Screen::forward, &Screen::back,
    &Screen::up, &Screen::down,};

int main()
{
    auto pmf = &Screen::get_cursor;
    pmf = &Screen::get;
    return 0;
}
