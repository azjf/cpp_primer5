#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H
#include <memory>
#include <vector>
#include <string>
#include "StrBlob.h"

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr() : curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) :
        wptr(a.data), curr(sz) { }

    const std::string &deref() const;
    ConstStrBlobPtr &incr();

    const std::string &operator*() const
    { auto p = check(curr, "dereference past end"); return (*p)[curr]; }

    const std::string *operator->() const
    { return &this->operator*(); }

private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};
#endif
