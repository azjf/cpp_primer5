#include <iostream>
#include <memory>
#include <vector>

class base
{
public:
    base() = default;
    base(const std::string &n) : basename(n) {}
    virtual ~base() = default;

    std::string name()
    {
        std::cout << "base::name()" << std::endl;
        return basename;
    }

    virtual void print(std::ostream &os)
    {
        std::cout << "base::print(std::ostream &)" << std::endl;
        os << basename;
    }

private:
    std::string basename;
};

class derived : public base
{
public:
    derived() = default;
    derived(const std::string &n, int ii) : base(n), i(ii) {}
    ~derived() = default;

    void print(std::ostream &os)
    {
        std::cout << "derived::print(std::ostream &)" << std::endl;
        base::print(os);
        os << " " << i;
    }

private:
    int i;
};

int main()
{
    base bobj;
    base *bp1 = &bobj;
    base &br1 = bobj;
    derived dobj;
    base *bp2 = &dobj;
    base &br2 = dobj;

    bobj.print(std::cout);
    dobj.print(std::cout);
    bp1->name();
    bp2->name();
    br1.print(std::cout);
    br2.print(std::cout);
    return 0;
}
