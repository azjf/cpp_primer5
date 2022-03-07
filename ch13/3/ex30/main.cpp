#include <iostream>
#include <unordered_map>
#include "HasPtr.h"

int main()
{
    HasPtr hasPtr1, hasPtr2(hasPtr1);
    hasPtr2 = hasPtr1;

    swap(hasPtr1, hasPtr2);
    return 0;
}
