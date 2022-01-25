#include <iostream>

int fact(int val);

int main()
{
    std::cout << "5! == " << fact(5) << std::endl;
    return 0;
}


int fact(int val) {
    if (val == 2) {
        return val;
    }
    return val * fact(val - 1);
}
