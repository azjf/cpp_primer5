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
    std::bitset<22> bs1("1000000010000100101110");
    std::cout << bs1 << std::endl;

    std::bitset<22> bs2;
    bs2.set(1);
    bs2.set(2);
    bs2.set(3);
    bs2.set(5);
    bs2.set(8);
    bs2.set(13);
    bs2.set(21);
    std::cout << bs2 << std::endl;
    return 0;
}
