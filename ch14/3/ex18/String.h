#ifndef STRING_H
#define STRING_H
#include <memory>

class String
{
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator!=(const String &lhs, const String &rhs);
    friend bool operator<(const String &lhs, const String &rhs);

public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char *);
    String(const String &);
    String &operator=(const String &);
    ~String();

    void push_back(char);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char *begin() const { return elements; }
    char *end() const { return first_free; }

private:
    static std::allocator<char> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<char *, char *>
        alloc_n_copy(const char *, const char *);
    void free();
    void reallocate();

    char *elements;
    char *first_free;
    char *cap;
};
#endif
