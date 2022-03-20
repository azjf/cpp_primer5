#include <iostream>
#include <memory>
#include <vector>

struct Base
{
    Base() : mem(0) {}

    int memfcn() { return 0; }

    virtual int fcn() { return 0; }

protected:
    int mem;
};

class D1 : public Base
{
public:
    int fcn() override { return 0; }
    virtual void f2() {}
};

class D2 : public D1
{
public:
    int fcn(int i) { return i; }
    int fcn() { return 0; }
    void f2() {}
};

int main()
{
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();
    bp2->fcn();
    bp3->fcn();

    Base *p1 = &d2obj;
    D1 *p2 = &d2obj;
    D2 *p3 = &d2obj;
    //p1->fcn(42);
    //p2->fcn(42);
    p3->fcn(42);
    return 0;
}
