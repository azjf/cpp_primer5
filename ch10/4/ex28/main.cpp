#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

void print(std::list<int> &ilst)
{
    for (const auto &i : ilst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> ilst1, ilst2, ilst3;

    std::unique_copy(ivec.cbegin(), ivec.cend(),
            std::inserter(ilst1, ilst1.begin()));
    print(ilst1);

    std::unique_copy(ivec.cbegin(), ivec.cend(),
            std::back_inserter(ilst2));
    print(ilst2);

    std::unique_copy(ivec.cbegin(), ivec.cend(),
            std::front_inserter(ilst3));
    print(ilst3);
    return 0;
}
