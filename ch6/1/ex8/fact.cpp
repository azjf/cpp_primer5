#include "fact.h"

int fact(int val) {
    if (val == 2) {
        return val;
    }
    return val * fact(val - 1);
}
