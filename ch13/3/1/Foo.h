#ifndef FOO_H
#define FOO_H
#include "HasPtr.h"

class Foo
{
    friend void swap(Foo &, Foo &);

private:
    HasPtr h;
};

inline
void swap(Foo &lhs, Foo &rhs)
{
    //std::swap(lhs.h, rhs.h);
    using std::swap;
    swap(lhs.h, rhs.h);
}
#endif
