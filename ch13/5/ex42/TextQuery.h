#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

#include "StrVec.h"

class QueryResult;

class TextQuery
{
    friend class QueryResult;

public:
    using line_no = size_t;
    TextQuery(std::ifstream &);

    QueryResult query(const std::string &sought) const;

private:
    std::shared_ptr<StrVec> file;
    std::map<std::string,
        std::shared_ptr<std::set<line_no>>> wm;
};
#endif
