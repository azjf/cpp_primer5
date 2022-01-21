#include <iostream>

int main()
{
    std::string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;
    for (auto c : s) {
        if (std::ispunct(c)) {
            ++punct_cnt;
        }
    }
    std::cout << punct_cnt
        << " punction characters in " << s << std::endl;

    for (auto &c : s) {
        c = std::toupper(c);
    }
    std::cout << s << std::endl;

    s = "some string";
    if (!s.empty()) {
        s[0] = toupper(s[0]);
    }
    std::cout << s << std::endl;

    for (decltype(s.size()) index = 0;
            index != s.size() && !std::isspace(s[index]); ++index) {
        s[index] = std::toupper(s[index]);
    }
    std::cout << s << std::endl;

    const std::string hexdigits = "0123456789ABCDEF";
    std::cout << "Enter a series of numbers between 0 and 15"
        << " separated by space. Hit Enter when finished: "
        << std::endl;
    std::string result;
    std::string::size_type n;
    while (std::cin >> n) {
        if (n < hexdigits.size()) {
            result += hexdigits[n];
        }
    }
    std::cout << "Your hex number is: " << result << std::endl;
    return 0;
}
