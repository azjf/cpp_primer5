#include <iostream>
#include <stdexcept>

int main()
{
    int n1 = 0, n2 = 0;
    if (!(std::cin >> n1 >> n2)) {
        return -1;
    }
    if (n2 == 0) {
        throw std::runtime_error("divisor is zero");
    }
    std::cout << n1 / n2 << std::endl;
}
