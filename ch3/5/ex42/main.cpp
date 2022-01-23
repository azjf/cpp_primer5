#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5};
    int iarr[5];
    for (size_t i = 0; i != 5; ++i) {
        iarr[i] = ivec[i];
    }
    return 0;
}
