#include <iostream>
#include <vector>

std::string f(const std::string &name,
        const std::string &pre, const std::string &post)
{
    std::string s(name);
    s.insert(s.begin(), pre.begin(), pre.end());
    s.insert(s.end(), post.begin(), post.end());
    return s;
}


int main()
{
    std::cout << f("Hello", "Mr. ", " Jr. ") << std::endl;
    return 0;
}
