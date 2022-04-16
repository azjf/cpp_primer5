#include <iostream>
#include <fstream>

union Token
{
    char cval;
    int ival;
    double dval;
};

int main()
{
    Token first_token = {'a'};
    Token last_token;
    Token *pt = new Token;

    last_token.cval = 'z';
    pt->ival = 42;

    union {
        char cval;
        int ival;
        double dval;
    };
    cval = 'c';
    ival = 42;
    return 0;
}
