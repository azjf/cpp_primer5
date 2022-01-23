#include <iostream>
#include <vector>

int main()
{
    int arr1[10], arr2[10];
    for (size_t i = 0; i < 10; ++i) {
        arr1[i] = i;
        arr2[i] = i;
    }

    bool result = true;
    for (size_t i = 0; i != 10; ++i) {
        if (arr1[i] != arr2[i]) {
            result = false;
            break;
        }
    }
    std::cout << (result ? "equal" : "not equal") << std::endl;

    std::vector<int> ivec1, ivec2;
    for (size_t i = 0; i < 10; ++i) {
        ivec1.push_back(i);
        ivec2.push_back(i);
    }

    bool result2 = true;
    for (decltype(ivec1.size()) i = 0; i != ivec1.size(); ++i) {
        if (ivec1[i] != ivec2[i]) {
            result2 = false;
            break;
        }
    }
    std::cout << (result2 ? "equal" : "not equal") << std::endl;
    return 0;
}
