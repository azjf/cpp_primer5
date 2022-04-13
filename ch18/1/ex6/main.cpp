#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

class exceptionType {};

int main()
{
    try {
        throw new exceptionType();
    } catch(exceptionType *pet) {
        std::cout << "exceptionType *" << std::endl;
    }

    try {
        throw std::exception();
    } catch(...) {
        std::cout << "..." << std::endl;
    }

    typedef int EXCEPTYPE;
    try {
        //EXCEPTYPE i = 1;
        int i = 1;
        throw i;
    } catch(EXCEPTYPE) {
        std::cout << "EXCEPTYPE" << std::endl;
    }
    return 0;
}
