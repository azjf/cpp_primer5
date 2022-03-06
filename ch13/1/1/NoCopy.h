#ifndef NOCOPY_H
#define NOCOPY_H

struct NoCopy
{
    NoCopy() = default;
    NoCopy(const NoCopy &) = delete;
    NoCopy &operator=(const NoCopy &) = delete;
    ~NoCopy() = default;
};

#endif
