#ifndef PRIVATECOPY_H
#define PRIVATECOPY_H

class PrivateCopy
{
    PrivateCopy(const PrivateCopy &);
    PrivateCopy &operator=(const PrivateCopy &);

public:
    PrivateCopy() = default;
    //~PrivateCopy();
    ~PrivateCopy() = default;
};

#endif
