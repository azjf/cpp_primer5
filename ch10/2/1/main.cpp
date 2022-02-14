#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <iterator>

void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main()
{
    std::vector<int> ivec{1, 2, 3, 4};
    int isum = std::accumulate(ivec.cbegin(), ivec.cbegin(), 0);

    std::vector<std::string> svec{"hello", "world"};
    std::string ssum = std::accumulate(svec.cbegin(), svec.cbegin(), std::string(""));

    std::vector<std::string> roster1{"hello", "world"};
    std::list<std::string> roster2{"hello", "world"};
    std::equal(roster1.cbegin(), roster1.cbegin(), roster2.cbegin());

    std::fill(ivec.begin(), ivec.end(), 0);
    std::fill(ivec.begin(), ivec.begin() + ivec.size() / 2, 0);

    std::vector<int> ivec2;
    std::fill_n(ivec2.begin(), ivec2.size(), 0);
    //std::fill_n(ivec2.begin(), 10, 0);

    auto it = std::back_inserter(ivec2);
    *it = 42;
    std::fill_n(std::back_inserter(ivec2), 10, 0);

    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1) / sizeof(*a1)];
    auto ret = std::copy(std::begin(a1), std::end(a1), a2);

    std::list<int> ilst{1, 2, 3, 4};
    std::replace(ilst.begin(), ilst.end(), 0, 42);
    std::replace_copy(ilst.begin(), ilst.end(),
            std::back_inserter(ivec), 0, 42);

    std::vector<std::string> words{"the", "quick", "red", "fox",
        "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    return 0;
}
