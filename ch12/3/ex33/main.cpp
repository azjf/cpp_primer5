#include <iostream>
#include <fstream>
#include "TextQuery.h"
#include "QueryResult.h"

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") {
            break;
        }
        print(std::cout, tq.query(s)) << std::endl;
    }

    std::cout << "\n\n" << std::endl;
    QueryResult qr = tq.query("hi");
    auto pfile = qr.get_file();
    auto it = qr.begin();
    while (it != qr.end()) {
        std::cout << (*pfile)[*it++] << std::endl;
    }
}

int main()
{
    std::ifstream ifs("text");
    runQueries(ifs);
    return 0;
}
