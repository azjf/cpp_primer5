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

    QueryResult eval(const TextQuery &t) const
    {
        std::cout << "Query::eval(const TextQuery &)" << std::endl;
        return q->eval(t);
    }
    std::string rep() const
    {
        std::cout << "Query::rep()" << std::endl;
        return q->rep();
    }

private:
    Query(std::shared_ptr<Query_base> query) : q(query)
    {
        std::cout << "Query(std::shared_ptr<Query_base>)" << std::endl;
    }
    std::shared_ptr<Query_base> q;
};

inline
Query::Query(const std::string &s) : q(new WordQuery(s))
{
    std::cout << "Query(const std::string &)" << std::endl;
}

std::ostream &operator<<(std::ostream &, const Query &);
#endif
