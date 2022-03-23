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

    std::string sought1("sought1"), sought2("sought2");
    Query andq = Query(sought1) & Query(sought2);
    std::cout << andq << std::endl;

    {
    std::ifstream ifs("text");
    TextQuery tq(ifs);

    Query q1 = Query("Daddy");
    runQueries(q1, tq);

    Query q2 = ~Query("Alice");
    runQueries(q2, tq);

    Query q3 = Query("hair") | Query("Alice");
    runQueries(q3, tq);

    Query q4 = Query("hair") & Query("Alice");
    runQueries(q4, tq);

    Query q5 = Query("fiery") & Query("bird") | Query("wind");
    runQueries(q5, tq);
    }
    return 0;
}
