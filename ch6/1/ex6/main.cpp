#include <iostream>

int func(int n) {
    static size_t num = 0;
    num += n;
    return num;
}

int main()
{
    func(1);
    std::cout << func(2) << std::endl;
    return 0;
}
