#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> words;
    std::string word;
    while (std::cin >> word) {
        words.push_back(word);
    }

    if (words.empty()) {
        std::cerr << "no word" << std::endl;
        return -1;
    }
    int maxCnt = 0, cnt = 0;
    std::string maxWord;
    word = "";
    auto it = words.cbegin();
    while (it != words.cend()) {
        if (*it == word) {
            ++cnt;
        } else {
            if (maxCnt < cnt) {
                maxWord = word;
                maxCnt = cnt;
            }
            cnt = 1;
            word = *it;
        }
        ++it;
    }
    std::cout << maxWord << ": " << maxCnt << std::endl;
    return 0;
}
