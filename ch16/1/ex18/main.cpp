#include <iostream>
#include <memory>
#include <vector>
#include <list>

template <typename T, typename U, typename V> void f1(T, U, V);
template <typename T> T f2(int &TT);
template <typename T> inline T foo(T, unsigned int *);
template <typename T> void f4(T, T);
typedef char Ctype;
template <typename Ctype> Ctype f5(Ctype a);

int main()
{
    return 0;
}
