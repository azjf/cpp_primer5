#include <iostream>
#include <stdexcept>

int main()
{
    int n1 = 0, n2 = 0;
    if (!(std::cin >> n1 >> n2)) {
        return -1;
    }
    std::cout << n1 / n2 << std::endl;
}
