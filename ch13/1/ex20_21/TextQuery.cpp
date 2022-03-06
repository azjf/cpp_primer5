#include <fstream>
#include <sstream>
#include "TextQuery.h"
#include "QueryResult.h"

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>)
{
    std::string text;
    while (std::getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines) {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const
{
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file);
    } else {
        return QueryResult(sought, loc->second, file);
    }
}

TextQuery::TextQuery(const TextQuery &tq) :
    file(std::shared_ptr<std::vector<std::string>>(
        new std::vector<std::string>(*tq.file))
    )
{
    for (const auto &map_it : tq.wm) {
        wm[map_it.first] = std::shared_ptr<std::set<line_no>>(
            new std::set<line_no>(*map_it.second)
        );
    }
}

TextQuery &TextQuery::operator=(const TextQuery &rhs)
{
    file = std::shared_ptr<std::vector<std::string>>(
        new std::vector<std::string>(*rhs.file)
    );
    for (const auto &map_it : rhs.wm) {
        wm[map_it.first] = std::shared_ptr<std::set<line_no>>(
            new std::set<line_no>(*map_it.second)
        );
    }
    return *this;
}
