#include <iostream>

int abs(int val);

int main()
{
    std::cout << "abs(-5) = " << abs(-5) << std::endl;
    return 0;
}


int abs(int val) {
    return val >= 0 ? val : -val;
}
