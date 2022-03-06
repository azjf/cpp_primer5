#ifndef NUMBERED_H
#define NUMBERED_H
#include<string>

struct numbered
{
    numbered() = default;
    numbered(const numbered &n) : mysn(n.mysn + "2") {}

    std::string mysn = "1";
};

#endif
