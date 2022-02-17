#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <set>

class TextQuery;

class QueryResult
{
    friend std::ostream &print(std::ostream &os, const QueryResult &qr);

public:
    QueryResult() = default;

    QueryResult(const std::string &s,
            std::shared_ptr<std::vector<std::string>> pv,
            std::shared_ptr<std::map<std::string, std::set<size_t>>> pm) :
        word(s), text_sp(pv), word_map_sp(pm) { }

    QueryResult(const std::string &s) : QueryResult(s,
            std::shared_ptr<std::vector<std::string>>(),
            std::shared_ptr<std::map<std::string, std::set<size_t>>>()) { }

    bool found() const { return text_sp && word_map_sp; }

    const std::set<size_t> &get_line_nums() const { return (*word_map_sp)[word]; }

    const std::string &get_line(size_t n) const { return (*text_sp)[n - 1]; }

private:
    const std::string word;
    const std::shared_ptr<std::vector<std::string>> text_sp;
    const std::shared_ptr<std::map<std::string, std::set<size_t>>> word_map_sp;
};

std::ostream &print(std::ostream &os, const QueryResult &qr);
#endif
