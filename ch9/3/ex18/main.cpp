#include <iostream>
#include <deque>

int main()
{
    std::deque<std::string> sd;
    std::string word;
    while (std::cin >> word) {
        sd.push_back(word);
    }

    auto it = sd.cbegin();
    while (it != sd.cend()) {
        std::cout << *it++ << " ";
    }
    std::cout << std::endl;
    return 0;
}
