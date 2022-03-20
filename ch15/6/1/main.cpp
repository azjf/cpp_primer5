#include <iostream>
#include <memory>
#include <vector>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Disc_quote.h"

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

struct Base
{
    Base() : mem(0) {}

    int memfcn() { return 0; }

    virtual int fcn() { return 0; }

protected:
    int mem;
};

struct Derived : Base
{
    Derived() = default;
    Derived(int i) : mem(i) {}
    int get_mem() { return mem; }

    int memfcn(int i) { return i; }

protected:
    int mem;
};

struct Derived2 : Base
{
    Derived2(int i) : mem(i) {}
    int get_mem() { return Base::mem; }

protected:
    int mem;
};

class D1 : public Base
{
public:
    int fcn(int i) { return i; }
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
    {
    Bulk_quote bulk("isbn", 1.1, 10, 0.1);
    std::cout << bulk.isbn() << std::endl;
    }

    {
    Bulk_quote bulk;
    Bulk_quote *bulkP = &bulk;
    Quote * itemP = &bulk;
    bulkP->discount_policy();
    //itemP->discount_policy();

    Derived d(42);
    std::cout << d.get_mem() << std::endl;

    Derived2 d2(42);
    std::cout << d2.get_mem() << std::endl;
    }

    {
    Derived d;
    Base b;
    b.memfcn();
    d.memfcn(10);
    //d.memfcn();
    d.Base::memfcn();
    }

    {
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();
    bp2->fcn();
    bp3->fcn();

    D1 *d1p = &d1obj;
    D2 *d2p = &d2obj;
    //bp2->f2();
    d1p->f2();
    d2p->f2();

    Base *p1 = &d2obj;
    D1 *p2 = &d2obj;
    D2 *p3 = &d2obj;
    //p1->fcn(42);
    p2->fcn(42);
    p3->fcn(42);
    }
    return 0;
}
