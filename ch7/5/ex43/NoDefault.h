#ifndef NODEFAULT_H
#define NODEFAULT_H
#include <string>

class NoDefault
{
public:
    NoDefault(int i) { }
};

class C
{
public:
    C() : no_default(NoDefault(0)) { }

private:
    NoDefault no_default;
};
#endif
