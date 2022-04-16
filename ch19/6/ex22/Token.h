#ifndef TOKEN_H
#define TOKEN_H
#include <string>

#include "Sales_data.h"

class Token
{
public:
    Token() : tok(INT), ival(0) {}
    Token(const Token &t) : tok(t.tok) { copyUnion(t); }
    Token &operator=(const Token &);
    ~Token() { if (tok == STR) {  sval.~basic_string(); } }

    Token &operator=(const std::string &);
    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);
    Token &operator=(const Sales_data &);

private:
    enum {INT, CHAR, DBL, STR, SAL} tok;
    union {
        char cval;
        int ival;
        double dval;
        std::string sval;
        Sales_data sdval;
    };
    void copyUnion(const Token &);
};
#endif
