#ifndef STRBLOB_H
#define STRBLOB_H
#include <vector>
#include <string>
#include <memory>

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);

public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    std::string &front();
    std::string &back();

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0) :
        wptr(a.data), curr(sz) { }


    std::string &deref() const;
    StrBlobPtr &incr();

private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

inline
StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

inline
StrBlobPtr StrBlob::end() { auto ret = StrBlobPtr(*this, data->size());
    return ret; }
#endif
