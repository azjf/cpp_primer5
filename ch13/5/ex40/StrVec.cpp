#include <memory>

#include "StrVec.h"

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(std::initializer_list<std::string> il) :
    elements(nullptr), first_free(nullptr), cap(nullptr)
{
    int sz = il.size();
    if (sz == 0) {
        return;
    }
    //auto newdata = alloc_n_copy(il.begin(), il.end());
    //elements = newdata.first;
    //first_free = cap = newdata.second;
    elements = alloc.allocate(sz);
    first_free = cap = std::uninitialized_copy(il.begin(), il.end(), elements);
}

void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t newcapacity)
{
    if (newcapacity <= capacity()) {
        return;
    }
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::resize(size_t newsize)
{
    if (newsize < size()) {
        for (auto p = elements + newsize; p != first_free; ++p) {
            alloc.destroy(p);
        }
        first_free = elements + newsize;
    } else if (newsize > size()) {
        reserve(newsize);
        for (auto p = first_free; p != elements + newsize; ++p) {
            alloc.construct(p, "");
        }
        first_free = elements + newsize;
    }
}
