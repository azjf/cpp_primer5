#ifndef WORD_QUERY_H
#define WORD_QUERY_H
#include "Query_base.h"
#include "QueryResult.h"

class WordQuery : public Query_base
{
    friend class Query;

private:
    WordQuery(const std::string &s) : query_word(s) {}

    QueryResult eval(const TextQuery &t) const override
        { return t.query(query_word); }
    std::string rep() const override { return query_word; }

    std::string query_word;
};
#endif
