#include <iostream>
#include <list>

void print(std::list<std::string> &words)
{
    for (const auto &s : words) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

void elimDups(std::list<std::string> &words)
{
    words.sort();
    print(words);
    words.unique();
    print(words);
}

int main()
{
    std::list<std::string> words{"the", "quick", "red", "fox",
        "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    return 0;
}
