#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
#include "QueryResult.h"

class TextQuery
{
public:
    TextQuery(std::ifstream &ifs);

    QueryResult query(const std::string &word);

private:
    std::shared_ptr<std::vector<std::string>> text_sp;
    std::shared_ptr<std::map<std::string, std::set<size_t>>> word_map_sp;
};
#endif
