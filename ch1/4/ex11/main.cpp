#include <iostream>

int main()
{
    int val1 = 0, val2 = 0;
    std::cout << "Please enter two numbers:" << std::endl;
    std::cin >> val1 >> val2;
    
    if (val1 < val2) {
        while (val1 <= val2) {
            std::cout << val1++ << " ";
        }
    } else {
        while (val1 >= val2) {
            std::cout << val1-- << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
