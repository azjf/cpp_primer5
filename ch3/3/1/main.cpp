#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v2;
    for (int i = 0; i != 100; ++i) {
        v2.push_back(i);
    }

    std::string word;
    std::vector<std::string> text;
    while (std::cin >> word) {
        text.push_back(word);
    }
    return 0;
}
