#include <fstream>
#include <iostream>
#include "Sales_data.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        return -1;
    }
    std::ifstream input(argv[1]);
    if (!input) {
        return -1;
    }

    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
