#ifndef NODTOR_H
#define NODTOR_H

struct NoDtor
{
    NoDtor() = default;
    ~NoDtor() = delete;
};

#endif
