#include <iostream>
#include <vector>
#include <algorithm>

class ReadString
{
public:
    ReadString() = default;
    ReadString(std::istream &i) : is(i) {}

    std::string operator()()
    {
        std::string ret;
        if (!std::getline(is, ret)) {
            ret = "";
        }
        return ret;
    }

    bool good() { return is.good(); }

private:
    std::istream &is = std::cin;
};

int main()
{
    ReadString rs(std::cin);
    std::vector<std::string> svec;
    while (rs.good()) {
        svec.push_back(rs());
    }
    std::for_each(svec.cbegin(), svec.cend(),
            [] (const std::string &s) { std::cout << s << std::endl; });
    return 0;
}
