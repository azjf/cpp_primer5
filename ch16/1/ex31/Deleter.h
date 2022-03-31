#ifndef DELETER_H
#define DELETER_H
struct Deleter
{
    template <typename T>
    void operator()(T *p) const
    {
        delete p;
    }
};
#endif
