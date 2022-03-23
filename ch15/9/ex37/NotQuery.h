#ifndef NOTQUERY_H
#define NOTQUERY_H
#include "Query.h"
#include "Query_base.h"
#include "QueryResult.h"

class NotQuery : public Query_base
{
    friend Query operator~(const Query &);

private:
    NotQuery(const Query &q) : query(q.q) {}

    std::string rep() const { return "~(" + query->rep() + ")"; }
    QueryResult eval(const TextQuery &) const;

    std::shared_ptr<Query_base> query;
};

inline
Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}
#endif
