

#ifndef __LC_CONTAINERS_VECTOR_H
#define __LC_CONTAINERS_VECTOR_H

#include <__lc_configs.h>

#include <cmath>
#include <type_traits>

#include "__lc_iterator/reverse_iterator.h"
#include "__lc_memory/allocator.h"

__LC_NAMESPACE_BEGIN

template <typename _Tp, typename _Allocator = lc::allocator<_Tp>>
class vector {
public:
    using allocator_type         = _Allocator;
    using value_type             = typename allocator_type::value_type;
    using size_type              = typename allocator_type::size_type;
    using difference_type        = typename allocator_type::difference_type;
    using reference              = typename allocator_type::reference;
    using const_reference        = typename allocator_type::const_reference;
    using pointer                = typename allocator_type::pointer;
    using const_pointer          = typename allocator_type::const_pointer;
    using iterator               = pointer;
    using const_iterator         = const_pointer;
    using reverse_iterator       = lc::reverse_iterator<iterator>;
    using const_reverse_iterator = lc::reverse_iterator<const_iterator>;

    static_assert(std::is_same<value_type, _Tp>::value,
                  "Allocator::value_type must be the same as _Tp");

public:

    __LC_CONSTEXPR vector() __LC_NOEXCEPT_(__LC_NOEXCEPT_(allocator_type())) {
        __init(0, value_type(), allocator_type());
    }

    __LC_EXPLICIT vector(const allocator_type &__alloc) __LC_NOEXCEPT {
        __init(0, value_type(), __alloc);
    }

    __LC_EXPLICIT vector(size_type             __count,
                         const allocator_type &__alloc = allocator_type()) {
        if (__count > 0) {
            __init(__count, value_type(), __alloc);
        }
    }

    __LC_EXPLICIT vector(size_type __count, const value_type &__value,
                         const allocator_type &__alloc = allocator_type()) {
        if (__count > 0) {
            __init(__count, __value, __alloc);
        }
    }

    template <typename _InputIterator>
    __LC_EXPLICIT vector(_InputIterator __first, _InputIterator __last,
                         const allocator_type &__alloc = allocator_type()) {
        __LC_ASSERT(__first <= __last, "vector::vector: invalid range");
        __init(__first, __last, __alloc);
    }

    vector(const vector &__other) {
        __init(__other, allocator_type());
    }

    vector(vector &&__other) {
        __init(std::move(__other), allocator_type());
    }

    vector(const vector &__other, const allocator_type &__alloc) {
        __init(__other, __alloc);
    }

    vector(vector &&__other, const allocator_type &__alloc) {
        __init(std::move(__other), __alloc);
    }

    vector(std::initializer_list<value_type> __init_list,
           const allocator_type             &__alloc = allocator_type()) {
        __init(__init_list.begin(), __init_list.end(), __alloc);
    }

    ~vector() {
        // TODO: destroy elements
    }

private:

    void __init(size_type __count, const value_type &__value,
                const allocator_type &__alloc) {
        __alloc_    = __alloc;
        __begin_    = __alloc_.allocate(__count);
        __end_      = __begin_ + __count;
        __capacity_ = __end_;
    }

    template <typename _InputIterator>
    void __init(_InputIterator __first, _InputIterator __last,
                const allocator_type &__alloc) {
        __alloc_    = __alloc;
        __begin_    = __alloc_.allocate(__last - __first);
        __end_      = __begin_ + (__last - __first);
        __capacity_ = __end_;
        std::copy(__first, __last, __begin_);
    }

    void __init(const vector &__other, const allocator_type &__alloc) {
        __alloc_    = __alloc;
        __begin_    = __alloc_.allocate(__other.size());
        __end_      = __begin_ + __other.size();
        __capacity_ = __end_;
        std::copy(__other.begin(), __other.end(), __begin_);
    }

    void __init(vector &&__other, const allocator_type &__alloc) {
        __alloc_    = __alloc;
        __begin_    = __alloc_.allocate(__other.size());
        __end_      = __begin_ + __other.size();
        __capacity_ = __end_;
        std::move(__other.begin(), __other.end(), __begin_);
    }

private:
    allocator_type __alloc_;
    pointer        __begin_;
    pointer        __end_;
    pointer        __capacity_;
};

__LC_NAMESPACE_END

#endif  // __LC_CONTAINERS_VECTOR_H
