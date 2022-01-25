#include <iostream>
#include <stdexcept>

int main()
{
    int n1, n2;
    while (std::cin >> n1 >> n2) {
        try {
            if (n2 == 0) {
                throw std::runtime_error("divisor is zero");
            }
            std::cout << n1 / n2 << std::endl;
        } catch (std::runtime_error &err) {
            std::cout << err.what()
                << "\nTry Again ? Enter y or n: ";
            char c;
            if (!(std::cin >> c) || c == 'n') {
                break;
            }
        }
    }
}
