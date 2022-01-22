#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> text{"hello", "world", "hi", "word1"};
    std::string sought("hi");
    auto beg = text.cbegin(), end = text.cend();
    auto mid = text.cbegin() + (end - beg) / 2;
    while (mid != end && *mid != sought) {
        if (sought < *mid) {
            end = mid;
        } else {
            beg = mid + 1;
        }
        mid = beg + (end - beg) / 2;
    }
    std::cout << (*mid == sought ? "found" : "not found") << std::endl;
    return 0;
}
