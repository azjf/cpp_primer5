#ifndef STRBLOBPPTR_H
#include "StrBlob.h"

class StrBlobPPtr
{
public:
    StrBlobPPtr() = default;
    StrBlobPPtr(StrBlobPtr &p) : sbp(&p) {}
    StrBlobPtr operator->() { return *sbp; }

private:
    StrBlobPtr *sbp = nullptr;
};
#endif
