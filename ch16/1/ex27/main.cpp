#include <iostream>
#include <memory>
#include <vector>
#include <list>

template <typename T> class Stack {};
void f1(Stack<char>) {}

class Exercise
{
    Stack<double> &rsd;
    Stack<int> si;
};

int main()
{
    Stack<char> *sc;
    f1(*sc);
    int iObj = sizeof(Stack<std::string>);
    return 0;
}
