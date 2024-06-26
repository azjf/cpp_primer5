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

public:
    Query(const std::string &);
    Query(const Query &query) : q(query.q), count(query.count + 1) {}
    Query(Query &&query) : q(query.q), count(query.count)
    {
        query.q = nullptr;
        query.count = 0;
    }
    Query &operator=(const Query &rhs)
    {
        if (!--count) {
            delete q;
        }
        q = rhs.q;
        count = ++rhs.count;
        return *this;
    }
    Query &operator=(Query &&rhs)
    {
        if (!--count) {
            delete q;
        }
        q = rhs.q;
        count = rhs.count;
        rhs.q = nullptr;
        rhs.count = 0;
        return *this;
    }
    virtual ~Query()
    {
        if (!--count) {
            delete q;
        }
    }

    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }

private:
    Query(Query_base *query) : q(query), count(1) {}
    Query_base *q = nullptr;
    mutable std::size_t count = 0;
};

inline
Query::Query(const std::string &s) : q(new WordQuery(s)), count(1) {}

std::ostream &operator<<(std::ostream &, const Query &);
#endif
