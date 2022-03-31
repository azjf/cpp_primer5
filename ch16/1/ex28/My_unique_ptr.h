#ifndef MY_UNIQUE_PTR
#define MY_UNIQUE_PTR
#include <memory>

#include "Deleter.h"

template <typename, typename>
class My_unique_ptr;

template <typename T, typename D>
void swap(My_unique_ptr<T, D> &, My_unique_ptr<T, D> &);

template <typename T, typename D = Deleter>
class My_unique_ptr
{
    //friend void swap<T, D>(My_unique_ptr<T, D> &, My_unique_ptr<T, D> &);

public:
    My_unique_ptr() = default;
    explicit My_unique_ptr(T *p) : ptr(p) {}
    explicit My_unique_ptr(T *p, const D &d) : ptr(p), deleter(d) {}
    My_unique_ptr(const My_unique_ptr &) = delete;
    My_unique_ptr(My_unique_ptr &&other) noexcept
        : ptr(other.ptr) { other.ptr = nullptr; }
    ~My_unique_ptr();

    My_unique_ptr &operator=(const My_unique_ptr &) = delete;
    My_unique_ptr &operator=(My_unique_ptr &&) noexcept;
    //My_unique_ptr &operator=(std::nullptr_t) noexcept;

    T &operator*() const { return *ptr; }
    T *operator->() const { return &operator*(); }

    operator bool() const { return ptr; }

    void swap(My_unique_ptr<T, D> &other) { swap(*this, other); }

    T *get() const { return ptr; }
    void reset();
    void reset(T *p) { reset(); ptr = p; }
    T *release();

private:
    T *ptr = nullptr;
    D deleter = D();
};

template <typename T, typename D>
My_unique_ptr<T, D>::~My_unique_ptr()
{
    // reset();
    if (!ptr) {
        return;
    }
    deleter(ptr);
}

template <typename T, typename D>
My_unique_ptr<T, D> &My_unique_ptr<T, D>::operator=(My_unique_ptr &&rhs)
    noexcept
{
    if (rhs.ptr != ptr) {
        //swap(*this, rhs);
        swap(*this, std::move(rhs)); // ?
    }
    return *this;
}

template <typename T, typename D>
void My_unique_ptr<T, D>::reset()
{
    if (!ptr) {
        return;
    }
    deleter(ptr);
    ptr = nullptr;
}

template <typename T, typename D>
T *My_unique_ptr<T, D>::release()
{
    T *ret = ptr;
    reset();
    return ret;
}

template <typename T, typename D>
void swap(My_unique_ptr<T, D> &rhs, My_unique_ptr<T, D> &lhs)
{
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.deleter, rhs.deleter);
}
#endif
