#include <iostream>

std::string (*func())[10];

typedef std::string sa[10];
sa *func();

auto func() -> std::string (*)[10];

std::string str_arr[10];
decltype(str_arr) *func();

int main()
{
    return 0;
}
