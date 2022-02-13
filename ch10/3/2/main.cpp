#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std::placeholders;


bool check_size(const std::string &s, std::string::size_type sz)
{
    return s.size() >= sz;
}

std::ostream &print(std::ostream &os, const std::string &s, char c)
{
    return os << s << c;
}

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

    //auto wc = std::find_if(words.begin(), words.end(),
    //        [sz] (const std::string &a)
    //        { return a.size() >= sz; });
    //auto wc = std::find_if(words.begin(), words.end(),
    //        [=] (const std::string &a)
    //        { return a.size() >= sz; });
    auto wc = std::find_if(words.begin(), words.end(),
            std::bind(check_size, std::placeholders::_1, sz));
    auto count = words.end() - wc;
    std::cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << std::endl;

    //std::for_each(wc, words.end(),
    //        [] (const std::string &s) { std::cout << s << " "; });
    //std::for_each(wc, words.end(),
    //        [&os, c] (const std::string &s) { os << s << c; });
    //std::for_each(wc, words.end(),
    //        [&, c] (const std::string &s) { os << s << c; });
    //std::for_each(wc, words.end(),
    //        [=, &os] (const std::string &s) { os << s << c; });
    std::for_each(wc, words.end(), std::bind(print, std::ref(os), _1, ' '));
    std::cout << std::endl;
}

void fcn1()
{
    size_t v1 = 42;
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f();
}

void fcn2()
{
    size_t v1 = 42;
    auto f = [&v1] { return v1; };
    v1 = 0;
    auto j = f();
}

void fcn3()
{
    size_t v1 = 42;
    auto f = [v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f();
}

void fcn4()
{
    size_t v1 = 42;
    auto f = [&v1] { return ++v1; };
    v1 = 0;
    auto j = f();
}

int main()
{
    std::vector<std::string> words = {"the", "quick", "red", "fox",
        "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 5);

    auto f = [] { return 42; };
    std::cout << f() << std::endl;

    fcn1();
    fcn2();
    fcn3();
    fcn4();

    std::vector<int> vi{-1, 0, 1};
    std::transform(vi.begin(), vi.end(), vi.begin(),
            [] (int i) { return i < 0 ? -i : i; });
    std::transform(vi.begin(), vi.end(), vi.begin(),
            [] (int i) { if (i < 0) return -i; else return i; });
    std::transform(vi.begin(), vi.end(), vi.begin(),
            [] (int i) -> int { if (i < 0) return -i; else return i; });

    auto check6 = std::bind(check_size, std::placeholders::_1, 6);
    std::string s = "hello";
    bool b1 = check6(s);

    auto isShorter = [] (const std::string &s1, const std::string &s2)
    { return s1.size() < s2.size(); };
    std::sort(words.begin(), words.end(), std::bind(isShorter, _2, _1));
    return 0;
}
