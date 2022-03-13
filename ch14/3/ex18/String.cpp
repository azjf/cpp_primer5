#include <memory>
#include <algorithm>
#include <iostream>
#include <cstring>

#include "String.h"

std::allocator<char> String::alloc;

String::String(const char *cp)
{
    auto newdata = alloc_n_copy(cp, cp + std::strlen(cp));
    elements = newdata.first;
    first_free = cap = newdata.second;
}

void String::push_back(char c)
{
    chk_n_alloc();
    alloc.construct(first_free++, c);
}

std::pair<char *, char *>
String::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void String::free()
{
    if (elements) {
        //for (auto p = first_free; p != elements;) {
        //    alloc.destroy(--p);
        //}
        alloc.deallocate(elements, cap - elements);
    }
}

String::String(const String &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

String::~String() { free(); }

String &String::operator=(const String &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void String::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        //alloc.construct(dest++, std::move(*elem++));
        alloc.construct(dest++, *elem++);
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    //std::for_each(s.elements, s.first_free, [&os] (char &c) { os << c; });
    os << std::string(s.elements, s.size());
    return os;
}

bool operator==(const String &lhs, const String &rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (auto p1 = lhs.begin(), p2 = rhs.begin(); p1 != lhs.end(); ++p1, ++p2) {
        if (*p1 != *p2) {
            return false;
        }
    }
    return true;
    //return std::string(lhs.elements, lhs.size())
    //    == std::string(rhs.elements, rhs.size());
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    auto p1 = lhs.begin(), p2 = rhs.begin();
    while (p1 != lhs.end() && p2 != rhs.end() && *p1 == *p2) {
        ++p1;
        ++p2;
    }
    if (p2 == rhs.end()) {
        return false;
    }
    return p1 == lhs.end() || *p1 < *p2;
    //return std::string(lhs.elements, lhs.size())
    //    < std::string(rhs.elements, rhs.size());
}
