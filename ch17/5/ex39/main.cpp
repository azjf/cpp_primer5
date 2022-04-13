#include <ios>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <random>
#include <ctime>

int main()
{
    std::fstream inOut("copyOut", std::fstream::ate | std::fstream::in
            | std::fstream::out);
    if (!inOut) {
        std::cerr << "Unable to open file!" << std::endl;
        return EXIT_SUCCESS;
    }
    auto end_mark = inOut.tellg();
    inOut.seekg(0, std::fstream::beg);
    std::size_t cnt = 0;
    std::string line;
    while (inOut && inOut.tellg() != end_mark && std::getline(inOut, line)) {
        cnt += line.size() + 1;
        auto mark = inOut.tellg();
        inOut.seekp(0, std::fstream::end);
        inOut << cnt;
        if (mark != end_mark) {
            inOut << " ";
        }
        inOut.seekg(mark);
    }
    inOut.seekp(0, std::fstream::end);
    inOut << "\n";
    return 0;
}
