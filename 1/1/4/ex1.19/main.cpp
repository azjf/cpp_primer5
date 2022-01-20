#include <iostream>

int main()
{
    int v1 = 0, v2 = 0;
    std::cout << "Please enter two numbers:" << std::endl;
    std::cin >> v1 >> v2;
    
    if (v1 < v2) {
        for (int i = v1; i <= v2; ++i) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    } else {
        for (int i = v1; i >= v2; --i) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
