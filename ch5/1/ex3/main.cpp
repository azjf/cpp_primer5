#include <iostream>

int main()
{
    int sum = 0, val = 1;
    // while (val <= 10) {
    //     sum += val;
    //     ++val;
    // }
    while (sum += val, ++val <= 10);
    std::cout << "Sum of 1 to 10 inclusive is "
        << sum << std::endl;
    return 0;
}
