#include <iostream>
#include <memory>

std::shared_ptr<int> clone(int p)
{
    //return new int(p);
    return std::shared_ptr<int>(new int(p));
}

void process(std::shared_ptr<int> ptr)
{
}

int main()
{
    std::shared_ptr<double> p1;
    std::shared_ptr<int> p2(new int(42));
    auto p22 = std::make_shared<int>(42);

    //std::shared_ptr<int> p1 = new int(1024);
    std::shared_ptr<int> p2_2(new int(1024));

    std::shared_ptr<int> p(new int(42));
    process(p);
    int i = *p;

    int *x(new int(1024));
    //process(x);
    process(std::shared_ptr<int>(x));
    int j = *x;
    std::cout << j << std::endl;

    std::shared_ptr<int> p3(new int(42));
    int *q = p3.get();
    {
        //auto qq = std::shared_ptr<int>(q);
    }
    int foo = *p3;
    std::cout << foo << std::endl;

    //p = new int(1024);
    p.reset(new int(1024));

    std::shared_ptr<std::string> ps(new std::string("hello"));
    if (!ps.unique()) {
        ps.reset(new std::string(*ps));
    }
    std::string newVal("Hello");
    *ps = newVal;
    return 0;
}
