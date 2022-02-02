#include "Account.h"

void Account::rate(double newRate)
{
    interestRate = newRate;
}

double Account::interestRate = initRate();

constexpr int Account::period;
