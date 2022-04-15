#include <iostream>
#include <fstream>
#include "Query.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

int main()
{
    AndQuery aq;
    Query_base *pqb = &aq;
    if (AndQuery *paq = dynamic_cast<AndQuery *>(pqb)) {
        std::cout << "succeeded" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }

    OrQuery oq;
    pqb = &oq;
    if (AndQuery *paq = dynamic_cast<AndQuery *>(pqb)) {
        std::cout << "succeeded" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
    return 0;
}
