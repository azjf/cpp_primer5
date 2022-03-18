#include <iostream>
#include <memory>
#include <vector>
#include "Quote.h"
#include "Bulk_quote.h"

int main()
{
    Quote base("0-201-82470-1", 50);
    base.debug() << std::endl;

    Bulk_quote derived("0-201-82470-1", 50, 5, .19);
    derived.debug() << std::endl;
    return 0;
}
