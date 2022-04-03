#ifndef VEC_H
#define VEC_H
#include <string>

template <typename T>
class Vec
{
public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(const Vec &);
    Vec &operator=(const Vec &);
    ~Vec();
    Vec(Vec &&s) noexcept;
    Vec &operator=(Vec &&) noexcept;
    Vec &operator=(std::initializer_list<T>);

    T &operator[](std::size_t n) { return elements[n]; }
    const T &operator[](std::size_t n) const { return elements[n]; }

    void push_back(const T &);
    void push_back(T &&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }
    template <typename ...Args> void emplace_back(Args &&...);

private:
    static std::allocator<T> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<T *, T *>
        alloc_n_copy(const T *, const T *);
    void free();
    void reallocate();

    T *elements;
    T *first_free;
    T *cap;
};


template <typename T>
template <typename ...Args>
inline void Vec<T>::emplace_back(Args &&...args)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}




////////////////////////////////////////////////////////////////////////////////
// Vec.cpp
#include <memory>

template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
void Vec<T>::push_back(const T &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
void Vec<T>::push_back(T &&s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

template <typename T>
std::pair<T *, T *>
Vec<T>::alloc_n_copy(const T *b, const T *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
Vec<T>::Vec(const Vec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::~Vec() { free(); }

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
void Vec<T>::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    //auto newdata = alloc.allocate(newcapacity);
    //auto dest = newdata;
    //auto elem = elements;
    //for (size_t i = 0; i != size(); ++i) {
    //    alloc.construct(dest++, std::move(*elem++));
    //}
    //free();
    //elements = newdata;
    //first_free = dest;
    auto first = alloc.allocate(newcapacity);
    auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
            std::make_move_iterator(end()), first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

template <typename T>
Vec<T>::Vec(Vec &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

template <typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept
{
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template <typename T>
Vec<T> &Vec<T>::operator=(std::initializer_list<T> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
#endif
