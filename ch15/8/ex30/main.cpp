#include <iostream>
#include <memory>
#include <vector>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Disc_quote.h"
#include "Basket.h"

int main()
{
    Basket basket;
    basket.add_item(Quote("0-201-82470-1", 50));
    basket.add_item(Quote("0-201-82470-1", 50));
    basket.add_item(Quote("0-201-82470-1", 50));
    basket.add_item(Bulk_quote("0-201-82470-2", 50, 2, .15));
    basket.add_item(Bulk_quote("0-201-82470-2", 50, 2, .15));
    basket.add_item(Bulk_quote("0-201-82470-2", 50, 2, .15));
    basket.total_receipt(std::cout);
    return 0;
}
