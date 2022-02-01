#ifndef X_H
#define X_H
struct X
{
    friend void f() {}
    //X() { f(); }
    void g();
    void h();
};
#endif
