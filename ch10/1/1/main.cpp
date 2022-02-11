#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> vec{1, 2, 42, 3, 4};
    int val = 42;
    auto result = std::find(vec.cbegin(), vec.cend(), val);
    std::cout << "The value " << val
        << (result == vec.cend() ? " is not present" : " is present")
        << std::endl;

    std::vector<std::string> lst{"hello", "world", "a value"};
    std::string val2 = "a value";
    auto result2 = std::find(lst.cbegin(), lst.cend(), val2);

    int ia[] = {27, 210, 12, 47, 109, 83};
    int val3 = 83;
    int *result3 = std::find(std::begin(ia), std::end(ia), val3);
    result3 = std::find(ia + 1, ia + 4, val);
    return 0;
}
