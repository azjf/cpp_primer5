#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data cur;
    std::string isbn;
    int cnt = 0;
    double price = 0.0, revenue = 0.0;
    if (!(std::cin >> isbn >> cnt >> price)) {
        std::cerr << "No data!" << std::endl;
        return -1;
    }
    revenue = cnt * price;
    while (std::cin >> cur.isbn >> cur.numSold >> cur.price) {
        if (isbn == cur.isbn) {
            cnt += cur.numSold;
            revenue += cur.numSold * cur.price;
        } else {
            std::cout << isbn << " " << cnt << " "
                << revenue << " " << revenue / cnt << std::endl;
            isbn = cur.isbn;
            cnt = cur.numSold;
            revenue = cur.numSold * cur.price;
        }
    }
    std::cout << isbn << " " << cnt << " "
        << revenue << " " << revenue / cnt << std::endl;
    return 0;
}
