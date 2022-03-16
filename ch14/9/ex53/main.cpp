#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

class SmallInt
{
    friend SmallInt operator+(const SmallInt &, const SmallInt &);

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

SmallInt operator+(const SmallInt &lhs, const SmallInt &rhs)
    { return SmallInt(lhs.val + rhs.val); }

int main()
{
    SmallInt s1;
    //double d = s1 + 3.14;
    double d = (int) s1 + 3.14;
    d = s1 + SmallInt(3.14);
    return 0;
}
