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
    {
    std::bitset<32> bitvec(1U);
    std::bitset<13> bitvec1(0xbeef);
    std::bitset<20> bitvec2(0xbeef);
    std::bitset<128> bitvec3(~0ULL);
    std::bitset<32> bitvec4("1100");
    std::string str("1111111000000011001101");
    std::bitset<32> bitvec5(str, 5, 4);
    std::bitset<32> bitvec6(str, str.size() - 4);

    unsigned long ulong = bitvec3.to_ulong();
    std::cout << "ulong = " << ulong << std::endl;
    ulong = bitvec2.to_ullong();
    }

    {
    std::bitset<32> bitvec(1U);
    bool is_set = bitvec.any();
    bool is_not_set = bitvec.none();
    bool all_set = bitvec.all();
    std::size_t onBits = bitvec.count();
    std::size_t sz = bitvec.size();

    bitvec.flip();
    bitvec.reset();
    bitvec.set();
    bitvec.flip(0);
    bitvec.set(bitvec.size() - 1);
    bitvec.set(0, 0);
    int i = 0;
    bitvec.reset(i);
    bitvec.test(0);

    bitvec[0] = 0;
    bitvec[31] = bitvec[0];
    bitvec[0].flip();
    ~bitvec[0];
    bool b = bitvec[0];

    std::bitset<16> bits;
    std::cin >> bits;
    std::cout << "bits: " << bits << std::endl;

    bool status;
    unsigned long quizA = 0;
    quizA |= 1UL << 27;
    status = quizA & (1UL << 27);
    quizA &= ~(1UL << 27);
    std::bitset<30> quizB;
    quizB.set(27);
    status = quizB[27];
    quizB.reset(27);
    }
    return 0;
}
