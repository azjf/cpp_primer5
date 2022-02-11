#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> ivec;
    int num;
    while (std::cin >> num) {
        ivec.push_back(num);
    }

    int val = 2;
    std::cout << std::count(ivec.cbegin(), ivec.cend(), val)
        << std::endl;
    return 0;
}
