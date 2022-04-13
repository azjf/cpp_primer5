#include <ios>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <memory>
#include <vector>
#include <list>

int main()
{
    std::ifstream ifs("infile");
    char sink[10]{'\0'};
    while (ifs.getline(sink, 10)) {
        //std::cout << sink << std::endl;
        std::cout << sink;
    }
    return 0;
}
