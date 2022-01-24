#include <iostream>
#include <vector>

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch;
    bool hasCharF = false;
    while (std::cin.get(ch)) {
        switch (std::tolower(ch)) {
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
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
            default:
                break;
        }

        if (hasCharF) {
            switch (ch) {
                case 'f':
                    ++ffCnt;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
                default:
                    break;
            }
            hasCharF = false;
        } else {
            hasCharF = ch == 'f';
        }
    }
    std::cout << "a: " << aCnt << '\n'
        << "e: " << eCnt << '\n'
        << "i: " << iCnt << '\n'
        << "o: " << oCnt << '\n'
        << "u: " << uCnt << "\n\n"
        << "\\ : " << spaceCnt << '\n'
        << "\\t: " << tabCnt << '\n'
        << "\\n: " << newlineCnt << "\n\n"
        << "ff: " << ffCnt << '\n'
        << "fl: " << flCnt << '\n'
        << "fi: " << fiCnt << std::endl;
    return 0;
}
