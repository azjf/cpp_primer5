#include <iostream>
#include <vector>

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (std::cin >> ch) {
        switch(std::tolower(ch)) {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
            default:
                break;
        }
    }
    std::cout << "a: " << aCnt << '\n'
        << "e: " << eCnt << '\n'
        << "i: " << iCnt << '\n'
        << "o: " << oCnt << '\n'
        << "u: " << uCnt << std::endl;
    return 0;
}
