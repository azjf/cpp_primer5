#include <iostream>
#include <vector>

int main()
{
    int num = 77;
    std:: cout << (num > 90 ? "high pass" :
        num > 75 ? "pass" :
        num >= 60 ? "low pass" : "fail")
        << std::endl;

    if (num > 90) {
        std::cout << "high pass" << std::endl;
    } else if (num > 75) {
        std::cout << "pass" << std::endl;
    } else if (num >= 60) {
        std::cout << "low pass" << std::endl;
    } else {
        std::cout << "fail" << std::endl;
    }
    return 0;
}
