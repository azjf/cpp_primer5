#include <iostream>
#include <fstream>
#include "Query.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

void runQueries(const Query &query, const TextQuery tq)
{
    std::cout << "Executing Query for: " << query << std::endl;
    std::cout << query.eval(tq) << std::endl;
}

int main()
{
    std::ifstream ifs("text");
    TextQuery tq(ifs);
    Query q = Query("Daddy");
    runQueries(q, tq);
    return 0;
}
