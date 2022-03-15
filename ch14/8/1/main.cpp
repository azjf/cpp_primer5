#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

struct absInt
{
    int operator()(int val) const { return val < 0 ? -val : val; }
};

class PrintString
{
public:
    PrintString (std::ostream &o = std::cout, char c = ' ') : os(o), sep(c) {}
    void operator()(const std::string &s) const { os << s << sep; }

private:
    std::ostream &os;
    char sep;
};

class ShorterString
{
public:
    bool operator()(const std::string &s1, const std::string &s2) const
    { return s1.size() < s2.size(); }
};

class SizeComp
{
public:
    SizeComp(std::size_t n) : sz(n) {}
    bool operator()(const std::string &s)  const { return s.size() >= sz; }

private:
    std::size_t sz;
};

int add(int i, int j) { return i + j; }
auto mod = [] (int i, int j) { return i % j; };
struct divide
{
    int operator()(int denominator, int divisor)
        { return denominator / divisor; }
};

int main()
{
    {
    int i = -42;
    absInt absObj;
    int ui = absObj(i);

    std::string s("hello");
    PrintString printer;
    printer(s);
    PrintString errors(std::cerr, '\n');
    errors(s);

    std::vector<std::string> vs{"hello", "world"};
    std::for_each(vs.begin(), vs.end(), PrintString(std::cerr, '\n'));
    }

    {
    std::vector<std::string> words{"hello", "world", "hi"};
    std::stable_sort(words.begin(), words.end(),
            [] (const std::string &a, const std::string &b)
            { return a.size() < b.size(); });
    std::stable_sort(words.begin(), words.end(), ShorterString());

    std::size_t sz = 4;
    auto wc = std::find_if(words.begin(), words.end(),
            [sz] (const std::string &a)
            { return a.size() >= sz; });
    wc = std::find_if(words.begin(), words.end(), SizeComp(sz));
    }

    {
    std::plus<int> intAdd;
    std::negate<int> intNegate;
    int sum = intAdd(10, 20);
    sum = intNegate(intAdd(10, 20));
    sum = intAdd(10, intNegate(10));

    std::vector<std::string> svec{"hello", "world", "hi"};
    std::sort(svec.begin(), svec.end(), std::greater<std::string>());

    std::vector<std::string *> nameTables{&svec[0], &svec[1]};
    std::sort(nameTables.begin(), nameTables.end(),
            [] (std::string *a, std::string *b) { return a < b; });
    std::sort(nameTables.begin(), nameTables.end(), std::less<std::string *>());
    }

    {
    std::map<std::string, int (*)(int, int)> binops;
    binops.insert({"+", add});
    binops.insert({"%", mod});

    std::function<int (int, int)> f1 = add;
    std::function<int (int, int)> f2 = divide();
    std::function<int (int, int)> f3 = [] (int i, int j) { return i * j; };
    std::cout << f1(4, 2) << std::endl;
    std::cout << f2(4, 2) << std::endl;
    std::cout << f3(4, 2) << std::endl;
    }

    {
    std::map<std::string, std::function<int (int, int)>> binops = {
        {"+", add},
        {"-", std::minus<int>()},
        {"/", divide()},
        {"*", [] (int i, int j) { return i * j; }},
        {"%", mod} };
    binops["+"](10, 5);
    binops["-"](10, 5);
    binops["/"](10, 5);
    binops["*"](10, 5);
    binops["%"](10, 5);

    class Sales_data;
    int add(int i, int j);
    Sales_data add(const Sales_data &, const Sales_data &);
    //binops.insert({"+", add});
    int (*fp)(int, int) = add;
    binops.insert({"+", fp});
    binops.insert({"+", [] (int a, int b) { return add(a, b); }});
    }
    return 0;
}
