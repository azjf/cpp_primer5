#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

#include "Sales_data.h"

int main()
{
    Sales_data item1, item2, sum;
    if (std::cin >> item1 >> item2) {
        try {
            sum = item1 + item2;
        } catch (const isbn_mismatch &e) {
            std::cerr << e.what() << ": left isbn(" << e.left
                << ") right isbn(" << e.right << ")" << std::endl;
        }
    }
    if (std::cin >> item1 >> item2) {
        sum = item1 + item2;
    }
    return 0;
}
