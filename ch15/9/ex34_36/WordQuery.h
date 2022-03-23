#ifndef WORD_QUERY_H
#define WORD_QUERY_H
#include "Query_base.h"
#include "QueryResult.h"

class WordQuery : public Query_base
{
    friend class Query;

private:
    WordQuery(const std::string &s) : query_word(s)
    {
        std::cout << "WordQuery(const std::string &)" << std::endl;
    }

    QueryResult eval(const TextQuery &t) const override
    {
        std::cout << "WordQuery::eval(const TextQuery &)" << std::endl;
        return t.query(query_word);
    }
    std::string rep() const override
    {
        std::cout << "WordQuery::rep()" << std::endl;
        return query_word;
    }

    std::string query_word;
};
#endif
