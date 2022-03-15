#include <iostream>
#include <vector>
#include <algorithm>

class If_then_else
{
public:
    int operator()(bool condition, int v1, int v2)
        { return condition ? v1 : v2; }
};

int main()
{
    If_then_else if_then_else;
    std::cout << if_then_else(true, 1, 2) << std::endl;
    return 0;
}
