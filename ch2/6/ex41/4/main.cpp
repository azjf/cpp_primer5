#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data cur;
    std::string isbn;
    int cnt = 0;
    double price = 0.0;
    if (!(std::cin >> isbn >> cnt >> price)) {
        return -1;
    }
    while (std::cin >> cur.isbn >> cur.numSold >> cur.price) {
        if (isbn == cur.isbn) {
            cnt += cur.numSold;
        } else {
            std::cout << isbn << ": " << cnt << std::endl;
            isbn = cur.isbn;
            cnt = cur.numSold;
        }
    }
    std::cout << isbn << ": " << cnt << std::endl;
    return 0;
}
