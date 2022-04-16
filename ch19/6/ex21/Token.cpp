#include "Token.h"

Token &Token::operator=(int i)
{
    if (tok == STR) {
        sval.~basic_string();
    }
    ival = i;
    tok = INT;
    return *this;
}

Token &Token::operator=(char c)
{
    if (tok == STR) {
        sval.~basic_string();
    }
    cval = c;
    tok = INT;
    return *this;
}

Token &Token::operator=(double d)
{
    if (tok == STR) {
        sval.~basic_string();
    }
    dval = d;
    tok = INT;
    return *this;
}

Token &Token::operator=(const std::string &s)
{
    if (tok == STR) {
        sval = s;
    } else {
        new(&sval) std::string(s);
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
    }
}

Token &Token::operator=(const Token &t)
{
    if (tok == STR && t.tok != STR) {
        sval.~basic_string();
    }
    if (tok == STR && t.tok == STR) {
        sval = t.sval;
    } else {
        copyUnion(t);
    }
    tok = t.tok;
    return *this;
}
