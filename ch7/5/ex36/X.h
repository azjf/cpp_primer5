#ifndef X_H
#define X_H
struct X
{
    //X(int i, int j) : base(i), rem(base % j) { }
    //int rem, base;
    X(int i, int j) : base(i), rem(i % j) { }
    int base, rem;
};
#endif
