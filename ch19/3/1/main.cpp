#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

enum Tokens {INLINE = 128, VIRTUAL = 129};
void ff(Tokens) { std::cout << "ff(Tokens)" <<std::endl; }
void ff(int) { std::cout << "ff(int)" <<std::endl; }

void newf(unsigned char) { std::cout << "newf(unsigned char)" << std::endl; }
void newf(int) { std::cout << "newf(int)" << std::endl; }

int main()
{
    enum class open_modes {input, output, append};
    enum color {red, yellow, green};
    enum {floatPrec = 6, double_Prec = 10, double_doublePrec = 10};

    //enum stoplight {red, yellow, green};
    enum class peppers {red, yellow, green};
    color eyes = green;
    //peppers p = green;
    color hair = color::red;
    peppers p2 = peppers::red;

    enum class intTypes {
        charTyp = 8, shortTyp = 16, intTyp = 16,
        longTyp = 32, long_longTyp = 64
    };
    const intTypes charbits = intTypes::charTyp;

    //open_modes om = 2;
    open_modes om;
    om = open_modes::input;

    int i = color::red;
    //int j = peppers::red;

    enum intValues : unsigned long long {
        charTyp = 255, shortType = 65535, intTyp = 65535,
        longTyp = 4294967295UL,
        long_longTyp = 18446744073709551615ULL
    };

    enum intValues : unsigned long long;
    enum class open_modes;
    //enum class intValues;
    //enum intValues;
    //enum intValues : long;

    Tokens curTok = INLINE;
    ff(128);
    ff(INLINE);
    ff(curTok);

    unsigned char uc = VIRTUAL;
    newf(VIRTUAL);
    newf(uc);
    return 0;
}
