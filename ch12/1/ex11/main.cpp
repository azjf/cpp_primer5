#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
}

int main()
{
    std::shared_ptr<int> p(new int(42));
    //process(std::shared_ptr<int>(p.get()));
    return 0;
}
