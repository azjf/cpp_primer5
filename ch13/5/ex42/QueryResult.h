#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>

#include "StrVec.h"

#include "TextQuery.h"

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
            std::shared_ptr<StrVec> f) :
        sought(s), lines(p), file(f) { }

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<StrVec> file;
};

std::ostream &print(std::ostream &os, const QueryResult &qr);
#endif
