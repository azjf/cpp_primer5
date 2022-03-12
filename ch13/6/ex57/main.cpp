#include <iostream>
#include <vector>
#include <algorithm>

class Foo
{
public:
    Foo &operator=(const Foo &) &;
    //Foo someMem() & const;
    Foo anotherMem() const &;

    Foo sorted() &&;
    Foo sorted() const &;
    //Foo sorted() const;

    using Comp = bool (const int &, const int &);
    Foo sorted(Comp *);
    Foo sorted(Comp *) const;

private:
    std::vector<int> data;
};

Foo &Foo::operator=(const Foo &rhs) &
{
    return *this;
}

Foo Foo::sorted() &&
{
    std::sort(data.begin(), data.end());
    return *this;
}

//Foo Foo::sorted() const &
//{
//    Foo ret(*this);
//    std::sort(ret.data.begin(), ret.data.end());
//    return ret;
//}

Foo Foo::sorted() const &
{
    return Foo(*this).sorted();
}

Foo foo;
Foo &retFoo() { return foo; }
Foo retVal() { return Foo(); }

int main()
{
    retVal().sorted();
    retFoo().sorted();
    return 0;
}
