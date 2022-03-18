#include <iostream>
#include <memory>
#include <vector>
#include "Quote.h"
#include "Bulk_quote.h"

class Base
{
public:
    static void statmem() {}
};

class Derived : public Base
{
    void f(const Derived &);
};

void Derived::f(const Derived &derived_obj)
{
    Base::statmem();
    Derived::statmem();
    derived_obj.statmem();
    statmem();
};

class Bulk_quote;

class NoDerived final {};
class Last final : Base {};
//class Bad : NoDerived {};
//class Bad2 : Last {}

int main()
{
    {
    Quote item;
    Bulk_quote bulk;
    Quote *p = &item;
    p = &bulk;
    Quote &r = bulk;
    }

    {
    Quote base;
    //Bulk_quote *bulkP = &base;
    //Bulk_quote &bulkRef = base;
    }

    {
    Bulk_quote bulk;
    Quote *itemP = &bulk;
    //Bulk_quote *bulkP = itemP;
    Bulk_quote *bulkP = dynamic_cast<Bulk_quote *>(itemP);
    Bulk_quote *bulkP2 = static_cast<Bulk_quote *>(itemP);
    }

    {
    Bulk_quote bulk;
    Quote item(bulk);
    item = bulk;
    }
    return 0;
}
