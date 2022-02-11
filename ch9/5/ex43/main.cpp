#include <iostream>
#include <vector>

std::string &replace(std::string &&s,
        const std::string &oldVal, const std::string &newVal)
{
    for (size_t i = 0; i <= s.size() - oldVal.size(); ++i) {
        if (s.substr(i, oldVal.size()) == oldVal) {
            //s.replace(i, oldVal.size(), newVal);
            auto b = s.begin() + i;
            auto it = s.erase(b, b + oldVal.size());
            s.insert(it, newVal.cbegin(), newVal.cend());
            i += newVal.size() - 1;
        }
    }
    return s;
}


int main()
{
    std::cout << replace(std::string("tho thru tho thru"), "tho", "though")
        << std::endl;
    std::cout << replace(std::string("tho thru tho thru"), "thru", "through")
        << std::endl;
    return 0;
}
