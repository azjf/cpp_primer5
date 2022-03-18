#include <iostream>
#include <memory>
#include <vector>

class base
{
public:
    base() = default;
    base(const std::string &n) : basename(n) {}
    virtual ~base() = default;

    std::string name() { return basename; }
    virtual void print(std::ostream &os) { os << basename; }

private:
    std::string basename;
};

class derived : public base
{
public:
    derived() = default;
    derived(const std::string &n, int ii) : base(n), i(ii) {}
    ~derived() = default;

    void print(std::ostream &os) { base::print(os); os << " " << i; }

private:
    int i;
};

int main()
{
    derived("hello", 1).print(std::cout);
    return 0;
}
