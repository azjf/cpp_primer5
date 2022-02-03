#include <iostream>
#include <list>

int main()
{
    std::list<std::string> sl;
    std::string word;
    while (std::cin >> word) {
        sl.push_back(word);
    }

    auto it = sl.cbegin();
    while (it != sl.cend()) {
        std::cout << *it++ << " ";
    }
    std::cout << std::endl;
    return 0;
}
