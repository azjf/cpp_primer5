#include <iostream>
#include <memory>

struct destination {};
struct connection {};

connection connect(destination *pd) { return connection(); }
void disconnect(connection &c) { }

void f(destination &d)
{
    connection c = connect(&d);
    std::shared_ptr<connection> pc(&c,
            [] (connection *c) { disconnect(*c); });
}

int main()
{
    destination d;
    f(d);
    return 0;
}
