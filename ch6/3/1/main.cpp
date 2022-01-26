#include <iostream>

void swap(int &v1, int &v2)
{
    if (v1 == v2) {
        return;
    }
    int tmp = v2;
    v2 = v1;
    v1 = tmp;
}

bool str_subrange(const std::string &str1, const std::string &str2)
{
    if (str1.size() == str2.size()) {
        return str1 == str2;
    }
    auto size = (str1.size() < str2.size())
        ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

const std::string &manip()
{
    std::string ret;
    if (!ret.empty()) {
        return ret;
    } else {
        return "Empty";
    }
}

std::string make_plural(size_t ctr, const std::string &word,
        const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

const std::string &shorterString(const std::string &s1, const std::string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

char &get_val(std::string &str, std::string::size_type ix)
{
    return str[ix];
}

int main()
{
    int v1 = 1, v2 = 2;
    swap(v1, v2);

    str_subrange("hello", "he");

    std::cout << make_plural(2, "apple", "s") << std::endl;

    std::cout << shorterString("hello", "hi") << std::endl;

    //std::cout << manip() << std::endl;

    std::string s1("hello"), s2("hi");
    auto sz = shorterString(s1, s2).size();

    std::string s("a value");
    std::cout << s << std::endl;
    get_val(s, 0) = 'A';
    std::cout << s << std::endl;
    return 0;
}
