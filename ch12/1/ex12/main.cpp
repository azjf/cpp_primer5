#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
}

int main()
{
    auto p = new int();
    auto sp = std::make_shared<int>();

    process(sp);
    //process(new int());
    //process(p);
    process(std::shared_ptr<int>(p));
    return 0;
}
