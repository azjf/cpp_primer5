#include <iostream>
#include <memory>

struct destination {};
struct connection {};

connection connect(destination *pd) { return connection(); }
void disconnect(connection &c) { }

void end_connection(connection *pc)
{
    disconnect(*pc);
}

void f(destination &d)
{
    connection c = connect(&d);
    std::shared_ptr<connection> pc(&c, end_connection);
}

int main()
{
    destination d;
    f(d);
    return 0;
}
