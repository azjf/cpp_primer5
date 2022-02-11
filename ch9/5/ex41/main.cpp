#include <iostream>
#include <vector>

int main()
{
    std::vector<char> cvec{'h', 'e', 'l', 'l', 'o'};
    std::string s(cvec.cbegin().base(), 5);
    std::cout << s << std::endl;
    return 0;
}
