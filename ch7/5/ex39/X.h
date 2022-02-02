#ifndef X_H
#define X_H
#include <iostream>

class X
{
public:
    X(std::istream &iss = std::cin) : is(iss) { }

private:
    std::istream &is;
};
#endif
