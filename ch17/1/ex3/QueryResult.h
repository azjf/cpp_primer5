#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>

#include "TextQuery.h"

//std::string sought;
//std::shared_ptr<std::set<TextQuery::line_no>> lines;
//std::shared_ptr<std::vector<std::string>> file;
typedef TextQuery::QueryResult QueryResult;

std::ostream &print(std::ostream &os, const QueryResult &qr);
#endif
