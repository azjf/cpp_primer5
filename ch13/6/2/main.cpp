#include <iostream>
#include <vector>
#include <algorithm>
#include "StrVec.h"

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

Foo Foo::sorted() const &
{
    Foo ret(*this);
    std::sort(ret.data.begin(), ret.data.end());
    return ret;
}

Foo foo;
Foo &retFoo() { return foo; }
Foo retVal() { return Foo(); }

int main()
{
    {
    StrVec vec;
    std::string s = "some string or another";
    vec.push_back(s);
    vec.push_back("done");
    }

    {
    std::string s1 = "a value", s2 = "another";
    auto n = (s1 + s2).find('a');
    s1 + s2 = "wow!";
    }

    {
    Foo i, j;
    i = j;
    retFoo() = j;
    //retVal() = j;
    i = retVal();
    }

    {
    retVal().sorted();
    retFoo().sorted();
    }
    return 0;
}
