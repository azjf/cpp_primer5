#ifndef BINARYQUERY_H
#define BINARYQUERY_H
#include "Query.h"
#include "Query_base.h"

class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) :
        lhs(l.q), rhs(r.q), opSym(s) {}
    std::string rep() const
        { return "(" + lhs->rep() + " " + opSym + " " + rhs->rep() + ")"; }

    std::shared_ptr<Query_base> lhs, rhs;
    std::string opSym;
};
#endif
