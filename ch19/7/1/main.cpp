#include <iostream>
#include <fstream>

int a, val;

void foo(int val)
{
    static int si;
    enum Loc {a = 1024, b};

    struct Bar
    {
        Loc locVal;
        int barVal;

        void fooBar(Loc i = a)
        {
            //barVal = val;
            barVal = ::val;
            barVal = si;
            locVal = b;
        }
    };
}

void foo()
{
    class Bar
    {
    public:
        class Nested;
    };

    class Bar::Nested {};
}

int main()
{
    foo(0);
    foo();
    return 0;
}
