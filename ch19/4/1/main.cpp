#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <functional>

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
    {
    const std::string Screen::*pdata;
    pdata = &Screen::contents;
    }

    {
    auto pdata = &Screen::contents;

    Screen myScreen, *pScreen = &myScreen;
    auto s = myScreen.*pdata;
    s = pScreen->*pdata;
    }

    {
    const std::string Screen::*pdata = Screen::data();
    Screen myScreen;
    auto s = myScreen.*pdata;

    auto pmf = &Screen::get_cursor;
    char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
    pmf2 = &Screen::get;
    //char Screen::*p(Screen::pos, Screen::pos) const;
    pmf = &Screen::get;
    //pmf = Screen::get;

    Screen *pScreen = &myScreen;
    char c1 = (pScreen->*pmf)();
    char c2 = (myScreen.*pmf2)(0, 0);
    //myScreen.*pmf();

    using Action = char (Screen::*)(Screen::pos, Screen::pos) const;
    Action get = &Screen::get;

    Screen &action(Screen &, Action = &Screen::get);
    action(myScreen);
    action(myScreen, get);
    action(myScreen, &Screen::get);

    myScreen.move(Screen::HOME);
    myScreen.move(Screen::DOWN);

    auto fp = &std::string::empty;
    std::vector<std::string> svec;
    //std::find_if(svec.begin(), svec.end(), fp);
    }

    std::function<bool (const std::string &)> fcn = &std::string::empty;
    std::vector<std::string> svec{"hello"};
    std::find_if(svec.begin(), svec.end(), fcn);

    std::vector<std::string *> pvec;
    std::function<bool (const std::string *)> fp = &std::string::empty;
    find_if(pvec.begin(), pvec.end(), fp);

    find_if(svec.begin(), svec.end(), std::mem_fn(&std::string::empty));
    auto f = std::mem_fn(&std::string::empty);
    f(*svec.begin());
    f(&svec[0]);

    auto it = std::find_if(svec.begin(), svec.end(),
            std::bind(&std::string::empty, std::placeholders::_1));
    auto f2 = std::bind(&std::string::empty, std::placeholders::_1);
    f2(*svec.begin());
    f2(&svec[0]);
    return 0;
}
