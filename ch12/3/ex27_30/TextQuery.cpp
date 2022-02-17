#include <sstream>
#include "TextQuery.h"

TextQuery::TextQuery(std::ifstream &ifs)
{
    text_sp = std::make_shared<std::vector<std::string>>();
    word_map_sp = std::make_shared<std::map<std::string, std::set<size_t>>>();
    std::string line;
    while (std::getline(ifs, line)) {
        text_sp->push_back(line);
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            (*word_map_sp)[word].insert(text_sp->size());
        }
    }
}

QueryResult TextQuery::query(const std::string &word)
{
    QueryResult result(word);
    auto map_it = (*word_map_sp).find(word);
    if (map_it != (*word_map_sp).cend()) {
        //result = QueryResult(word, text_sp, word_map_sp);
        return QueryResult(word, text_sp, word_map_sp);
    }
    return result;
}
