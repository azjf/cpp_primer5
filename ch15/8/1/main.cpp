#include <iostream>
#include <memory>
#include <vector>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Disc_quote.h"

int main()
{
    {
    std::vector<Quote> basket;
    basket.push_back(Quote("0-201-82470-1", 50));
    basket.push_back(Bulk_quote("0-201-82470-1", 50, 10, .25));
    std::cout << basket.back().net_price(15) << std::endl;
    }
    {
    std::vector<std::shared_ptr<Quote>> basket;
    basket.push_back(std::make_shared<Quote>("0-201-82470-1", 50));
    basket.push_back(
            std::make_shared<Bulk_quote>("0-201-82470-1", 50, 10, .25));
    std::cout << basket.back()->net_price(15) << std::endl;
    }
    return 0;
}
