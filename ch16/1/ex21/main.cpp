#include <iostream>
#include <memory>
#include <vector>
#include <list>

class DebugDelete
{
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}
    template <typename T> void operator()(T *p) const
    { os << "deleting unique_ptr" << std::endl; delete p; }

private:
    std::ostream &os;
};

int main()
{
    DebugDelete()(new int);
    return 0;
}
