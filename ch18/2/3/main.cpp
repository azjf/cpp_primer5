#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

namespace A
{
int i, j;
}

void f()
{
    using namespace A;
    std::cout << i * j << std::endl;
}

namespace blip
{
int i = 16, j = 15, k = 23;
}

int j = 0;

void manip()
{
    using namespace blip;
    ++i;
    //++j;
    ++::j;
    ++blip::j;
    int k = 97;
    ++k;
}

namespace A2
{
int i;

namespace B
{

int i;
int j;

int f1()
{
    int j;
    return j;
}

} // namespace B

int f2()
{
    return j;
}

int j = i;
} // namespace A2

namespace A3
{
int i;
int k;

class C1
{
public:
    C1(): i(0), j(0) {}
    int f1() { return k; }
    //int f2() { return h; }
    int f3();

private:
    int i;
    int j;
};

int h = i;
} //namespace A3

int A3::C1::f3() { return h; }

namespace A4
{
class C
{
    friend void f2();
    friend void f(const C &);
};
}

namespace NS
{
class Quote {};
void display(const Quote &) {}

void print(int);
}

class Bulk_item : public NS::Quote {};

namespace libs_R_us
{
    extern void print(int);
    extern void print(double);

    void print(int) {}
    void print(double) {}
}

void print(const std::string &) {}

using namespace libs_R_us;

void fooBar(int ival)
{
    print("Value: ");
    print(ival);
}

int main()
{
    std::string s;
    std::cin >> s;
    operator>>(std::cin, s);
    using std::operator>>;
    std::operator>>(std::cin, s);

    A4::C cobj;
    f(cobj);
    //f2();

    Bulk_item book1;
    display(book1);

    //using NS::print(int);
    using NS::print;

    return 0;
}

namespace A4
{
void f2() {}
void f(const C &) {}
}
