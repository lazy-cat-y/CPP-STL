

#ifndef __LC_MEMORY_ALLOCATOR_H
#define __LC_MEMORY_ALLOCATOR_H

#include <cstddef>
#include <limits>
#include <memory>
#include <new>
#include <type_traits>

#include "__lc_configs.h"

__LC_NAMESPACE_BEGIN

/*
Unlike the allocator implemented in SGI STL, the standard allocator works
without memory pool, because the standard allocator is designed to be used in
the standard containers, which are designed to be used in a general way.
Also, the standard allocator is designed for modern C++ and modern hardware,
which avoids the overhead of memory pool and memory fragmentation.
*/

template <class _Tp>
class allocator
    : private std::__non_trivial_if<!std::is_void<_Tp>::value, allocator<_Tp>> {
    static_assert(!std::is_volatile<_Tp>::value,
                  "std::allocator does not support volatile types");
public:
    typedef _Tp            value_type;
    typedef _Tp           *pointer;
    typedef const _Tp     *const_pointer;
    typedef _Tp           &reference;
    typedef const _Tp     &const_reference;
    typedef std::size_t    size_type;
    typedef std::ptrdiff_t difference_type;
    typedef std::true_type propagate_on_container_move_assignment;
    typedef std::true_type is_always_equal;

public:
    // constructor
    allocator() __LC_NOEXCEPT = default;
    allocator(const allocator &other) __LC_NOEXCEPT {};

    template <class U>
    allocator(const allocator<U> &other) __LC_NOEXCEPT {};

    // destructor
    ~allocator() = default;

    // address
#if __LC_CPP_STD_VER < 17
    pointer address(reference __x) const __LC_NOEXCEPT {
        return std::addressof(__x);
    }

    const_pointer address(const_reference __x) const __LC_NOEXCEPT {
        return std::addressof(__x);
    }
#endif

    // allocate
    _Tp *allocate(std::size_t __n, const void *) {
        return allocate(__n);
    }

    _Tp *allocate(std::size_t __n) {
        if (__n > max_size()) {
            std::__throw_bad_array_new_length();
        }
        return static_cast<_Tp *>(::operator new(__n * sizeof(_Tp)));
    }

    // deallocate
    void deallocate(_Tp *__p, std::size_t __n) {
        ::operator delete(__p);
    }

    // max_size
    size_type max_size() const __LC_NOEXCEPT {
        return std::numeric_limits<std::size_t>::max() / sizeof(_Tp);
    }

    // construct
    template <class _U, class... Args>
    void construct(_U *__p, Args &&...__args) {
        ::new ((void *)__p) _U(std::forward<Args>(__args)...);
    }

    // destroy
    template <class _U>
    void destroy(_U *p) {
        p->~_U();
    }
};

template <class _T, class _U>
bool operator==(const allocator<_T> &, const allocator<_U> &) {
    return true;
}

template <class _T, class _U>
bool operator!=(const allocator<_T> &, const allocator<_U> &) {
    return false;
}

__LC_NAMESPACE_END

#endif /* __LC_MEMORY_ALLOCATOR_H */
