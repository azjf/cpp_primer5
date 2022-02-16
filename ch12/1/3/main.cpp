#include <iostream>
#include <memory>

void f()
{
    std::shared_ptr<int> sp(new int(42));
}

void f2()
{
    int *ip = new int(42);
    delete ip;
}

struct destination { };
struct connection { };
connection connect(destination *d) { return connection(); }
void disconnect(connection) { }

void f(destination &d)
{
    connection c = connect(&d);
    disconnect(c);
}

void end_connection(connection *p) { disconnect(*p); }

void f2(destination &d)
{
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, end_connection);

    connection c2 = connect(&d);
    std::unique_ptr<connection, decltype(end_connection) *> p2(&c2, end_connection);
}

std::unique_ptr<int> clone(int p)
{
    return std::unique_ptr<int>(new int(p));
}

std::unique_ptr<int> clone2(int p)
{
    std::unique_ptr<int> ret(new int(p));
    return ret;
}

int main()
{
    f();
    f2();

    destination d;
    f(d);
    f2(d);

    std::unique_ptr<double> p1;
    std::unique_ptr<int> p2(new int(42));

    {
    std::unique_ptr<std::string> p1(new std::string("Stegosaurus"));
    //std::unique_ptr<std::string> p2(p1);
    std::unique_ptr<std::string> p3;
    //p3 = p2;
    
    std::unique_ptr<std::string> p2(p1.release());
    std::unique_ptr<std::string> p32(new std::string("Trex"));
    p2.reset(p32.release());

    p2.release();
    auto p = p2.release();
    }
    return 0;
}
