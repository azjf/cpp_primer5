#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "StrBlob.h"

class QueryResult;

class TextQuery
{
    friend class QueryResult;

public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);

    QueryResult query(const std::string &sought) const;

private:
    StrBlob file;
    std::map<std::string,
        std::shared_ptr<std::set<line_no>>> wm;
};
#endif
