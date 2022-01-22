#include <iostream>
#include <vector>

int main()
{
    std::vector<int> scores(11, 0);
    auto beg = scores.begin();

    unsigned grade;
    while (std::cin >> grade) {
        if (grade <= 100) {
            ++*(beg + grade / 10);
        }
    }

    for (auto &score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    return 0;
}
