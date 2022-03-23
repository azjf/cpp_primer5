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
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::ifstream ifs("text");
    TextQuery tq(ifs);
    runQueries(q, tq);
    return 0;
}
