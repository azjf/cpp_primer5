#include <iostream>

inline const std::string &
shorterString(const std::string &s1, const std::string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

constexpr int new_sz() { return 42; }
constexpr int foo = new_sz();

constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }
int arr[scale(2)];
int i = 2;
//int a2[scale(i)];

int main()
{
    int a2[scale(i)];
    return 0;
}
