#ifndef CONSTREF_H
#define CONSTREF_H
class ConstRef
{
public:
    ConstRef(int ii);

private:
    int i;
    const int ci;
    int &ri;
};
#endif
