#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>

#include "TextQuery.h"

class TextQuery::QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    QueryResult(std::string, std::shared_ptr<std::set<line_no>>,
            std::shared_ptr<std::vector<std::string>>);

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;

    static int static_mem;
};

std::ostream &print(std::ostream &os, const QueryResult &qr);
#endif
