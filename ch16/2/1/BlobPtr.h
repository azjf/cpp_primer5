#ifndef BLOBPTR_H
#define BLOBPTR_H
#include <vector>
#include <string>
#include <memory>

template <typename T> class BlobPtr;
template <typename T> class Blob;
template <typename T> bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
class BlobPtr
{
    friend bool operator==<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator!=<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator< <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

public:
    BlobPtr() : curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0) :
        wptr(a.data), curr(sz) { }

    T &operator*() const
        { auto p = check(curr, "dereference past end"); return (*p)[curr]; }
    T *operator->() const
        { return &this->operator*(); }

    T &operator[](std::size_t n) { return (*wptr.lock())[n]; }
    const T &operator[](std::size_t n) const
        { return (*wptr.lock())[n]; }

    BlobPtr &operator++();
    BlobPtr &operator--();
    //BlobPtr<T> &operator++();
    //BlobPtr<T> &operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);

private:
    std::shared_ptr<std::vector<T>>
        check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};




// BlobPtr.cpp
#include <stdexcept>

template <typename T>
std::shared_ptr<std::vector<T>>
    BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound BlobPtr<T>");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

//template <typename T>
//T &BlobPtr<T>::operator*() const
//{
//    auto p = check(curr, "dereference past end");
//    return (*p)[curr];
//}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    check(curr, "increment past end of BlobPtr<T>");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "decrement past begin of BlobPtr<T>");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    //BlobPtr<T> ret = *this;
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}
#endif
