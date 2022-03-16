#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

class SmallInt
{
public:
    SmallInt(int i = 0) : val(i)
    {
        if (i < 0 || i > 255) {
            throw std::out_of_range("Bad SamllInt value");
        }
    }

    operator int() const { return val; }
    //int operator int() const;
    //operator int(int = 0) const;
    //operator int*() const { return 42; }

private:
    std::size_t val;
};

struct LongDouble
{
    LongDouble(double = 0.0) {}
    operator double() { return 0; }
    operator float() { return 0; }
    LongDouble operator+(const SmallInt &) { return LongDouble(); }
};

LongDouble operator+(LongDouble &, double) { return LongDouble(); }

int main()
{
    SmallInt si;
    LongDouble ld;
    //ld = si + ld;
    ld = ld + si;
    return 0;
}
