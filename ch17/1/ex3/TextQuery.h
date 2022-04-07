#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

class TextQuery
{
    //friend class QueryResult;

public:
    using line_no = std::vector<std::string>::size_type;
    typedef std::tuple<std::string, std::shared_ptr<std::set<line_no>>,
        std::shared_ptr<std::vector<std::string>>> QueryResult;

    TextQuery(std::ifstream &);

    QueryResult query(const std::string &sought) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string,
        std::shared_ptr<std::set<line_no>>> wm;
};
#endif
