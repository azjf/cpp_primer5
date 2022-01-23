#include <iostream>

int main()
{
    int num = 0;
    while (std::cin >> num) {
        if (num == 42) {
            break;
        }
    }
    return 0;
}
