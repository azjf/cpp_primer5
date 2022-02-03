#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> svec;
    std::string word;
    auto iter = svec.begin();
    while (std::cin >> word) {
        iter = svec.insert(iter, word);
    }
    return 0;
}
