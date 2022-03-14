#include <stdexcept>
#include "StrBlob.h"

std::shared_ptr<std::vector<std::string>>
    StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

std::string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(std::size_t n)
{
    curr += n;
    check(curr, "invalid StrBlobPtr");
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(std::size_t n)
{
    curr -= n;
    check(curr, "invalid StrBlobPtr");
    return *this;
}

StrBlobPtr operator+(const StrBlobPtr &lhs, std::size_t n)
{
    StrBlobPtr ret(lhs);
    ret += n;
    return ret;
}

StrBlobPtr operator-(const StrBlobPtr &lhs, std::size_t n)
{
    StrBlobPtr ret(lhs);
    ret -= n;
    return ret;
}
