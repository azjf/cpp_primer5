#include <iostream>

int fact();

int main()
{
    std::cout << fact() << std::endl;
    return 0;
}


int fact(int val) {
    if (val == 2) {
        return val;
    }
    return val * fact(val - 1);
}

int fact() {
    int n = 0;
    if (!(std::cin >> n)) {
        return 0;
    }
    return fact(n);
}
