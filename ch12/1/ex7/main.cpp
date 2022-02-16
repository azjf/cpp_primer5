#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>> factory()
{
    return std::make_shared<std::vector<int>>();
}

std::istream &read(std::shared_ptr<std::vector<int>> pv, std::istream &is)
{
    int i;
    while (is >> i) {
        pv->push_back(i);
    }
    return is;
}

std::ostream &print(std::shared_ptr<std::vector<int>> pv, std::ostream &os)
{
    for (const auto &i : *pv) {
        os << i << " ";
    }
    os << std::endl;
    return os;
}

int main()
{
    auto pv = factory();
    read(pv, std::cin);
    print(pv, std::cout);
    return 0;
}
