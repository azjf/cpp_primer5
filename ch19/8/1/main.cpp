#include <iostream>

typedef unsigned int Bit;

class File
{
    Bit mode: 2;
    Bit modified: 1;
    Bit prot_owner: 3;
    Bit prot_group: 3;
    Bit prot_world: 3;

public:
    enum modes {READ = 01, WRITE = 02, EXECUTE = 03};
    File &open(modes);
    void close();
    void write();
    bool isRead() const;
    void setWrite();
};

void File::write()
{
    modified = 1;
}

void File::close()
{
    if (modified) {}
}

File &File::open(File::modes m)
{
    mode |= READ;
    if (m & WRITE) {}
    return *this;
}

inline bool File::isRead() const { return mode & READ; }
inline void File::setWrite() { mode |= WRITE; }

class Task {};
class Screen {};

class Foo
{
public:
    Foo(const volatile Foo &);
    Foo &operator=(volatile const Foo &);
    Foo &operator=(volatile const Foo &) volatile;
};

extern "C" std::size_t strlen(const char *);
extern "C"
{
    int strcmp(const char *, const char *);
    char *strcat(char *, const char *);
//#include <string.h>
}

extern "C" void (*pf)(int);

void (*pf1)(int);
extern "C" void (*pf2)(int);
//pf1 = pf2;

extern "C" void f1(void(*)(int));
extern "C" typedef void FC(int);
void f2(FC *);

extern "C" double calc(double dparam) { return 0; }

#ifdef __cplusplus
extern "C"
#endif
int strcmp(const char *, const char *);

extern "C" void print(const char *);
//extern "C" void print(int);

class SmallInt {};
class BigNum {};
extern "C" double calc(double);
extern SmallInt calc(const SmallInt &);
extern BigNum calc(const BigNum &);

int main()
{
    File file;

    constexpr int max_size = 1;
    volatile int display_register;
    volatile Task *curr_task;
    volatile int iax[max_size];
    volatile Screen bitmapBuf;

    volatile int v;
    int * volatile vip;
    volatile int *ivp;
    volatile int *volatile vivp;
    //int *ip = &v;
    ivp = &v;
    return 0;
}
