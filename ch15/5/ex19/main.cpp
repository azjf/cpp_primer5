#include <iostream>
#include <memory>
#include <vector>

class Base
{
public:
    void pub_mem() {}

protected:
    int prot_mem;

private:
    char priv_mem;
};

struct Pub_Derv : public Base
{
    int f() { return prot_mem; }
    //char g() { return priv_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base
{
    int f1() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base
{
    int f1() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
    int use_base() { return prot_mem; }
    void memfcn2(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv
{
    //int use_base() { return prot_mem; }
    //void memfcn2(Base &b) { b = *this; }
    //void memfcn21(Base &b) { b = *this; }
    //void memfcn22(::Base &b) { b = *this; }
    //void memfcn23(::Base &b) { b.operator=(*this); }
};

struct Derived_from_Protected : public Prot_Derv
{
    int use_base() { return prot_mem; }
    void memfcn2(Base &b) { b = *this; }
};

int main()
{
    return 0;
}
