#include <iostream>
#include <vector>

int main()
{
    std::string lastWord, word;
    bool result = false;
    while (std::cin >> word) {
        if (word == lastWord) {
            result = true;
            break;
        } else {
            lastWord = word;
        }
    }
    std::cout << (result ? lastWord : "no repeated word")
        << std::endl;
    return 0;
}
