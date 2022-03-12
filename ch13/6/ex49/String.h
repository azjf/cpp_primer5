#ifndef STRING_H
#define STRING_H
#include <memory>

class String
{
    friend std::ostream &operator<<(std::ostream &, const String &);

public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char *);
    String(const String &);
    String &operator=(const String &);
    ~String();
    String(String &&s) noexcept :
        elements(s.elements), first_free(s.first_free), cap(s.cap)
        { s.elements = s.first_free = s.cap = nullptr; }
    String &operator=(String &&rhs) noexcept;

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
