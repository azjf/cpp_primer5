#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std::placeholders;


class Check_size
{
public:
    Check_size(std::string::size_type n) : sz(n) {}
    bool operator()(const std::string &s) { return s.size() >= sz; }

private:
    std::string::size_type sz = 0;
};

class Print
{
public:
    Print(std::ostream &o, char ch) : os(o), c(ch) {}
    std::ostream &operator()(const std::string &s) { return os << s << c; }

private:
    std::ostream &os;
    char c;
};

class Less
{
public:
    bool operator()(const std::string &a, const std::string &b)
        { return a.size() < b.size(); }
};

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
    std::stable_sort(words.begin(), words.end(), Less());

    auto wc = std::find_if(words.begin(), words.end(), Check_size(sz));
    auto count = words.end() - wc;
    std::cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << std::endl;

    std::for_each(wc, words.end(), Print(os, ' '));
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> words = {"the", "quick", "red", "fox",
        "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 5);
    return 0;
}
