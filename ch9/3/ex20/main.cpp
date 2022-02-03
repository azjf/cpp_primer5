#include <iostream>
#include <list>
#include <deque>

int main()
{
    std::list<int> ilist{1, 2, 3, 4, 5};
    std::deque<int> ideque1, ideque2;
    for (const auto &i : ilist) {
        if (i % 2 == 0) {
            ideque1.push_back(i);
        } else {
            ideque2.push_back(i);
        }
    }
    return 0;
}
