#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H
#include <memory>
#include <functional>

#include "Deleter.h"

template <typename T>
class My_shared_ptr;

template <typename T>
void swap(My_shared_ptr<T> &lhs, My_shared_ptr<T> &rhs);

template <typename T>
class My_shared_ptr
{
    //friend void swap<T>(My_shared_ptr<T> &lhs, My_shared_ptr<T> &rhs);

public:
    My_shared_ptr() = default;
    explicit My_shared_ptr(T *p)
        : ptr(p), use(new std::size_t(1)), deleter(Deleter()) {}
    My_shared_ptr(const My_shared_ptr &other)
        : ptr(other.ptr), use(other.use), deleter(other.deleter) { ++*use; }
    My_shared_ptr(My_shared_ptr &&other) noexcept
        : ptr(other.ptr), use(other.use), deleter(std::move(other.deleter))
        { other.ptr = other.use = nullptr; }
    ~My_shared_ptr();

    My_shared_ptr &operator=(const My_shared_ptr &);
    My_shared_ptr &operator=(My_shared_ptr &&) noexcept;

    T &operator*() const { return *ptr; }
    T *operator->() const { return &operator*(); }

    operator bool() const { return ptr; }

    std::size_t use_count() const { return use ? *use : 0; }
    T *get() const { return ptr; }
    bool unique() const { return *use == 1; }
    void reset();
    void reset(T *);
    void reset(T *p, const std::function<void (T *)> &d);

private:
    T *ptr = nullptr;
    std::size_t *use = nullptr;
    std::function<void (T *)> deleter;
};

template <typename T>
inline My_shared_ptr<T>::~My_shared_ptr()
{
    // reset();
    if (--*use == 0) {
        deleter(ptr);
        delete use;
    }
}

template <typename T>
My_shared_ptr<T> &My_shared_ptr<T>::operator=(const My_shared_ptr &rhs)
{
    ++*rhs.use;
    if (--*use == 0) {
        deleter(ptr);
        delete use;
    }
    ptr = rhs.ptr;
    use = rhs.use;
    deleter = rhs.deleter;
    return *this;
}

template <typename T>
My_shared_ptr<T> &My_shared_ptr<T>::operator=(My_shared_ptr &&rhs) noexcept
{
    if (rhs.ptr != ptr) {
        //swap(*this, rhs);
        swap(*this, std::move(rhs)); // ?
    }
    return *this;
}

template <typename T>
void My_shared_ptr<T>::reset()
{
    if (!use) {
        return;
    }
    if (--*use == 0) {
        deleter(ptr);
        delete use;
    }
    ptr = nullptr;
    use = nullptr;
}

template <typename T>
void My_shared_ptr<T>::reset(T *p)
{
    if (p == ptr) {
        return;
    }
    reset();
    ptr = p;
    use = new std::size_t(1);
}

template <typename T>
void My_shared_ptr<T>::reset(T *p, const std::function<void (T *)> &d)
{
    reset(p);
    deleter = d;
}

template <typename T>
void swap(My_shared_ptr<T> &lhs, My_shared_ptr<T> &rhs)
{
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.use, rhs.use);
    swap(lhs.deleter, rhs.deleter);
}
#endif
