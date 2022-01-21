#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> svec;
    std::string word;
    while (std::cin >> word) {
        svec.push_back(word);
    }

    for (auto &word : svec) {
        for (auto &c : word) {
            c = std::toupper(c);
        }
    }

    for (auto &word : svec) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return 0;
}
