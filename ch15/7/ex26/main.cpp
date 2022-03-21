#include <iostream>
#include <memory>
#include <vector>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Disc_quote.h"

int main()
{
    {
        Quote q("isbn", 1.1);
    }

    std::cout << "\n" << std::endl;
    {
        Bulk_quote q("isbn", 1.1, 10, 0.1);
    }

    std::cout << "\n" << std::endl;
    {
        Quote q1("isbn", 1.1), q2 = q1;
        q2 = q1;
        q2 = std::move(q1);
    }

    std::cout << "\n" << std::endl;
    {
        Bulk_quote q1("isbn", 1.1, 10, 0.1), q2 = q1;
        q2 = q1;
        q2 = std::move(q1);
    }
    return 0;
}
