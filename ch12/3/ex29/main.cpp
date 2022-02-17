#include <iostream>
#include <fstream>
#include "TextQuery.h"
#include "QueryResult.h"

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    do {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") {
            break;
        }
        print(std::cout, tq.query(s)) << std::endl;
    } while (true);
}

int main()
{
    std::ifstream ifs("text");
    runQueries(ifs);
    return 0;
}
