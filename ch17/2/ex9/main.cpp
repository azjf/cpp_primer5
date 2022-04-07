#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <numeric>

int main()
{
    std::bitset<64> bitvec(32);
    std::bitset<32> bv(1010101);

    {
    std::string bstr;
    std::cin >> bstr;
    std::bitset<8> bv(bstr);
    }
    return 0;
}
