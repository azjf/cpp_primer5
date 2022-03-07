#include <iostream>
#include <unordered_map>
#include "HasPtr.h"
#include "Foo.h"

int main()
{
    HasPtr hasPtr1, hasPtr2(hasPtr1);
    hasPtr2 = hasPtr1;

    Foo f1, f2;
    using std::swap;
    swap(f1, f2);
    return 0;
}
