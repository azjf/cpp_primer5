#ifndef NODEFAULT_H
#define NODEFAULT_H
#include <string>

class NoDefault
{
public:
    NoDefault(const std::string &);
};
inline NoDefault::NoDefault(const std::string &s) { }

struct A
{
    NoDefault my_mem;
};

//A a;

struct B
{
    //B() { }
    NoDefault b_member;
};
#endif
