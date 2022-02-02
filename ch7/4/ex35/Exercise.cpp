#include "Exercise.h"

Exercise::Type Exercise::initVal()
{
    return 0;
}

Exercise::Type Exercise::setVal(Type param)
{
    val = param + initVal();
    return val;
}
