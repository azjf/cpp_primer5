#include <iostream>
#include <algorithm>
#include <vector>

bool is_ge_5(std::string &s)
{
    return s.size() >= 5;
}

int main()
{
    std::vector<std::string> words{"the", "quick", "red", "fox",
        "jumps", "over", "the", "slow", "red", "turtle"};
    const auto true_end = std::partition(words.begin(), words.end(), is_ge_5);
    auto it = words.cbegin();
    while (it != true_end) {
        std::cout << *it++ << " ";
    }
    std::cout << std::endl;
    return 0;
}
