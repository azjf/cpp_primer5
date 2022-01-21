#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec;
    int num = 0;
    while (std::cin >> num) {
        ivec.push_back(num);
    }
    return 0;
}
