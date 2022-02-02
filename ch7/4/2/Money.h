#ifndef MONEY_H
#define MONEY_H
#include <string>

typedef double Money;
extern std::string bal;

class Accout
{
public:
    Money balance() { return bal; }

private:
    //typedef double Money;
    Money bal;
};
#endif
