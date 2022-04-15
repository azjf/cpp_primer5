#include <iostream>
#include <fstream>
#include "Query.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

void f(const Query_base &qb)
{
    try {
        const AndQuery &aq = dynamic_cast<const AndQuery &>(qb);
        std::cout << "succeeded" << std::endl;
    } catch (std::bad_cast &) {
        std::cout << "failed" << std::endl;
    }
}

int main()
{
    f(AndQuery());
    f(OrQuery());
    return 0;
}
