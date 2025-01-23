

#ifndef __MEMORY_ALLOCATOR_H
#define __MEMORY_ALLOCATOR_H

#include <cstddef>
#include <limits>
#include <memory>
#include <new>
#include <type_traits>

#include "__lc_configs.h"

namespace lc {

/*
Unlike the allocator implemented in SGI STL, the standard allocator works
without memory pool, because the standard allocator is designed to be used in
the standard containers, which are designed to be used in a general way.
Also, the standard allocator is designed for modern C++ and modern hardware,
which avoids the overhead of memory pool and memory fragmentation.
*/

template<class _T>
class allocator {
public:
    typedef _T             value_type;
    typedef _T            *pointer;
    typedef const _T      *const_pointer;
    typedef _T            &reference;
    typedef const _T      &const_reference;
    typedef std::size_t    size_type;
    typedef std::ptrdiff_t difference_type;
    typedef std::true_type  propagate_on_container_move_assignment;
    typedef std::true_type  is_always_equal;

public:
    // constructor
    allocator() noexcept = default;
    // allocator(const allocator &other) noexcept;
    allocator(const allocator &other) __STL_NOEXCEPT {};

    template<class U>
    allocator(const allocator<U> &other) __STL_NOEXCEPT {};

    // destructor
    ~allocator() = default;

    // address
    // XXX: (deprecated in C++17)
    pointer address(reference __x) const __STL_NOEXCEPT {
        return std::addressof(__x);
    }

    const_pointer address(const_reference __x) const __STL_NOEXCEPT {
        return std::addressof(__x);
    }

    // allocate
    _T *allocate(std::size_t __n, const void *) {
        return allocate(__n);
    }

    _T *allocate(std::size_t __n) {
        if (__n > max_size()) {
            std::__throw_bad_array_new_length();
        }
        // __builtin_is_constant_evaluated()
        return static_cast<_T *>(::operator new(__n * sizeof(_T)));
    }

    // deallocate
    void deallocate(_T *__p, std::size_t __n) {
        ::operator delete(__p);
    }

    // max_size
    size_type max_size() const __STL_NOEXCEPT {
        return std::numeric_limits<std::size_t>::max() / sizeof(_T);
    }

    // construct
    template<class _U, class... Args>
    void construct(_U *__p, Args &&...__args) {
        ::new ((void *)__p) _U(std::forward<Args>(__args)...);
    }

    // destroy
    template<class _U>
    void destroy(_U *p) {
        p->~_U();
    }
};

template<class _T, class _U>
bool operator==(const allocator<_T> &, const allocator<_U> &) {
    return true;
}

template<class _T, class _U>
bool operator!=(const allocator<_T> &, const allocator<_U> &) {
    return false;
}

}  // namespace lc

#endif /* __MEMORY_ALLOCATOR_H */
