#include <iostream>
#include "Account.h"

int main()
{
    double r;
    r = Account::rate();

    Account ac1;
    Account *ac2 = &ac1;
    r = ac1.rate();
    r = ac2->rate();
    return 0;
}
