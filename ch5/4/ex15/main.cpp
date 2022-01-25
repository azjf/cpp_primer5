#include <iostream>
#include <vector>

int main()
{
    int num = 0;
    while (std::cin >> num && num != 3);
    bool isFound = num == 3;

    for (; std::cin >> num && num != 3;);
    isFound = num == 3;


    std::vector<int> ivec{1, 2, 3, 4, 5};
    for (auto it = ivec.begin(); it != ivec.end(); ++it) {
        *it *= *it;
    }

    decltype(ivec.size()) i = 0;
    while (i != ivec.size()) {
        ivec[i] *= ivec[i];
        ++i;
    }
    return 0;
}
