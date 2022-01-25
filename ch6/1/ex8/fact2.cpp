#include <iostream>
#include "fact.h"
#include "fact2.h"

int fact2() {
    int n = 0;
    if (!(std::cin >> n)) {
        return 0;
    }
    return fact(n);
}
