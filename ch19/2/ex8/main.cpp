#include <iostream>
#include <fstream>
#include "Query.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

int main()
{
    AndQuery aq;
    OrQuery oq;
    Query_base *pqb1 = &aq;
    Query_base *pqb2 = &oq;
    if (typeid(*pqb1) == typeid(*pqb2)) {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }

    if (typeid(*pqb1) == typeid(AndQuery)) {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }
    return 0;
}
