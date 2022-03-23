#ifndef QUERY_H
#define QUERY_H
#include "Query_base.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "WordQuery.h"

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
    friend class NotQuery;
    friend class BinaryQuery;
    friend class AndQuery;
    friend class OrQuery;

public:
    Query(const std::string &);

    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }

private:
    Query(std::shared_ptr<Query_base> query) : q(query) {}
    std::shared_ptr<Query_base> q;
};

inline
Query::Query(const std::string &s) : q(new WordQuery(s)) {}

std::ostream &operator<<(std::ostream &, const Query &);
#endif
