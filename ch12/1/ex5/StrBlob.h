#ifndef STRBLOB_H
#define STRBLOB_H
#include <vector>
#include <string>
#include <memory>

class StrBlob
{
    typedef std::vector<std::string>::size_type size_type;

public:
    StrBlob();
    explicit StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &s) { data->push_back(s); };
    void pop_back() {data->pop_back(); };

    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};
#endif
