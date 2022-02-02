#ifndef EXERCISE_H
#define EXERCISE_H
#include <string>

typedef std::string Type;
Type initVal();

class Exercise
{
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();

private:
    int val;
};
#endif
