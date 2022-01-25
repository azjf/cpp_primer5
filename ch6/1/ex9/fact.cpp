#include "Chapter6.h"

int fact(int num) {
    if (num == 2) {
        return num;
    }
    return num * fact(num - 1);
}
