#include "Token.h"

Token &Token::operator=(int i)
{
    if (tok == STR) {
        sval.~basic_string();
    } else if (tok == SAL) {
        sdval.~Sales_data();
    }
    ival = i;
    tok = INT;
    return *this;
}

Token &Token::operator=(char c)
{
    if (tok == STR) {
        sval.~basic_string();
    } else if (tok == SAL) {
        sdval.~Sales_data();
    }
    cval = c;
    tok = INT;
    return *this;
}

Token &Token::operator=(double d)
{
    if (tok == STR) {
        sval.~basic_string();
    } else if (tok == SAL) {
        sdval.~Sales_data();
    }
    dval = d;
    tok = INT;
    return *this;
}

Token &Token::operator=(const std::string &s)
{
    if (tok == SAL) {
        sdval.~Sales_data();
    }
    if (tok == STR) {
        sval = s;
    } else {
        new(&sval) std::string(s);
    }
    tok = STR;
    return *this;
}

Token &Token::operator=(const Sales_data &sd)
{
    if (tok == STR) {
        sval.~basic_string();
    }
    if (tok == SAL) {
        sdval = sd;
    } else {
        new(&sdval) Sales_data(sd);
    }
    tok = STR;
    return *this;
}

void Token::copyUnion(const Token &t)
{
    switch (t.tok) {
        case Token::INT:
            ival = t.ival;
            break;
        case Token::CHAR:
            cval = t.cval;
            break;
        case Token::DBL:
            dval = t.dval;
            break;
        case Token::STR:
            new(&sval) std::string(t.sval);
            break;
        case Token::SAL:
            new(&sdval) Sales_data(t.sdval);
            break;
    }
}

Token &Token::operator=(const Token &t)
{
    if (tok == STR && t.tok != STR) {
        sval.~basic_string();
    }
    if (tok == SAL && t.tok != SAL) {
        sdval.~Sales_data();
    }
    if (tok == STR && t.tok == STR) {
        sval = t.sval;
    } else if (tok == SAL && t.tok == SAL) {
        sdval = t.sdval;
    } else {
        copyUnion(t);
    }
    tok = t.tok;
    return *this;
}
