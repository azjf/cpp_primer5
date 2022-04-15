#include "QueryResult.h"

TextQuery::QueryResult::QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
        std::shared_ptr<std::vector<std::string>> f) :
    sought(s), lines(p), file(f) { }

std::string make_plural(std::string::size_type ctr,
        const std::string &word, const std::string &end)
{
    return (ctr > 1) ? word + end : word;
}

std::ostream &print(std::ostream &os, const TextQuery::QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << make_plural(qr.lines->size(), "time", "s") << std::endl;
    for (auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") "
            << *(qr.file->begin() + num) << std::endl;
    }
    return os;
}

int TextQuery::QueryResult::static_mem = 1024;
