#include <iostream>
#include <fstream>
#include "Query.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

int main()
{
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << q << std::endl;

    std::ifstream ifs("text");
    TextQuery tq(ifs);
    std::cout << q.eval(tq);
    return 0;
}
