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

    Query q1 = Query("fiery1") | Query("bird");
    runQueries(q1, tq);

    Query q2 = Query("fiery") | Query("bird2");
    runQueries(q2, tq);

    Query q3 = Query("fiery3") | Query("bird3");
    runQueries(q3, tq);
    return 0;
}
