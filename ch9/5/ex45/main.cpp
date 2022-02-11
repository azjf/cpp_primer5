#include <iostream>
#include <vector>

std::string f(const std::string &name,
        const std::string &pre, const std::string &post)
{
    std::string s(name);
    s.insert(s.begin(), pre.begin(), pre.end());
    //s.append(post.begin(), post.end());
    s.append(post);
    return s;
}


int main()
{
    std::cout << f("Hello", "Mr. ", " Jr. ") << std::endl;
    return 0;
}
