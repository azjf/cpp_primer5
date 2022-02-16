#include <iostream>
#include <vector>

std::vector<int> *factory()
{
    return new std::vector<int>();
}

std::istream &read(std::vector<int> *pv, std::istream &is)
{
    int i;
    while (is >> i) {
        pv->push_back(i);
    }
    return is;
}

std::ostream &print(const std::vector<int> *pv, std::ostream &os)
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
    //delete pv;
    read(pv, std::cin);
    //delete pv;
    print(pv, std::cout);
    delete pv;
    return 0;
}
