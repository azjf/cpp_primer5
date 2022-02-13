#include <iostream>
#include <algorithm>
#include <vector>

void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end());
    auto unique_end = std::unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}

std::string make_plural(size_t ctr,
        const std::string &word, const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

void biggies(std::vector<std::string> &words,
        std::string::size_type sz,
        std::ostream &os = std::cout, char c = ' ')
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(),
            [] (const std::string &a, const std::string &b)
            { return a.size() < b.size(); });

    auto wc = std::find_if(words.begin(), words.end(),
            [=] (const std::string &a)
            { return a.size() >= sz; });
    //auto count = words.end() - wc;
    auto count = std::count_if(words.cbegin(), words.cend(),
            [sz] (const std::string &s) { return s.size() >= sz; });
    std::cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << std::endl;

    std::for_each(wc, words.end(),
            [=, &os] (const std::string &s) { os << s << c; });
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> words = {"the", "quick", "red", "fox",
        "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 6);
    return 0;
}
