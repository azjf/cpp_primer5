#include <iostream>
#include <vector>
#include <algorithm>

class Equal
{
public:
    Equal(std::size_t n) : sz(n) {}
    bool operator()(const std::string &s) { return s.size() == sz; }

private:
    std::size_t sz = 0;
};

class Greeter
{
public:
    Greeter(std::size_t n) : sz(n) {}
    bool operator()(const std::string &s) { return s.size() >= sz; }

private:
    std::size_t sz = 0;
};

int main()
{
    std::vector<std::string> text;
    std::string s;
    while (std::cin >> s) {
        text.push_back(s);
    }

    for (int i = 1; i != 10; ++i) {
        std::cout << i << ": "
            << std::count_if(text.cbegin(), text.cend(), Equal(i))
            << std::endl;
    }
    std::cout << ">= 10: "
        << std::count_if(text.cbegin(), text.cend(), Greeter(10))
        << std::endl;
    return 0;
}
