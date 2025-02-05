

#ifndef __LC_CONTAINERS_ARRAY_H
#define __LC_CONTAINERS_ARRAY_H

#include <__lc_configs.h>

#include <algorithm>
#include <stdexcept>
#include <tuple>
#include <type_traits>

#include "__lc_iterator/iterator.h"
#include "__lc_iterator/reverse_iterator.h"

__LC_NAMESPACE_BEGIN

template <typename _Tp, std::size_t _Size>
struct array {
    using value_type             = _Tp;
    using size_type              = std::size_t;
    using difference_type        = std::ptrdiff_t;
    using reference              = value_type &;
    using const_reference        = const value_type &;
    using pointer                = value_type *;
    using const_pointer          = const value_type *;
    using iterator               = value_type *;
    using const_iterator         = const value_type *;
    using reverse_iterator       = lc::reverse_iterator<iterator>;
    using const_reverse_iterator = lc::reverse_iterator<const_iterator>;

    value_type __elems_[_Size];

    __LC_CONSTEXPR reference at(size_type __pos) {
        if (__pos >= _Size) {
            std::__throw_out_of_range("array::at");
        }
        return __elems_[__pos];
    }

    __LC_CONSTEXPR const_reference at(size_type __pos) const {
        if (__pos >= _Size) {
            std::__throw_out_of_range("array::at");
        }
        return __elems_[__pos];
    }

    __LC_CONSTEXPR reference operator[](size_type __pos) {
        __LC_ASSERT(__pos < _Size, "array::operator[]: index out of bounds");
        return __elems_[__pos];
    }

    __LC_CONSTEXPR const_reference operator[](size_type __pos) const {
        __LC_ASSERT(__pos < _Size, "array::operator[]: index out of bounds");
        return __elems_[__pos];
    }

    __LC_CONSTEXPR reference front() {
        return __elems_[0];
    }

    __LC_CONSTEXPR const_reference front() const {
        return __elems_[0];
    }

    __LC_CONSTEXPR reference back() {
        return __elems_[_Size - 1];
    }

    __LC_CONSTEXPR const_reference back() const {
        return __elems_[_Size - 1];
    }

    __LC_CONSTEXPR value_type *data() __LC_NOEXCEPT {
        return __elems_;
    }

    __LC_CONSTEXPR const value_type *data() const __LC_NOEXCEPT {
        return __elems_;
    }

    __LC_CONSTEXPR iterator begin() __LC_NOEXCEPT {
        return iterator(data());
    }

    __LC_CONSTEXPR const_iterator begin() const __LC_NOEXCEPT {
        return const_iterator(data());
    }

    __LC_CONSTEXPR const_iterator cbegin() const __LC_NOEXCEPT {
        return const_iterator(data());
    }

    __LC_CONSTEXPR iterator end() __LC_NOEXCEPT {
        return iterator(data() + _Size);
    }

    __LC_CONSTEXPR const_iterator end() const __LC_NOEXCEPT {
        return const_iterator(data() + _Size);
    }

    __LC_CONSTEXPR const_iterator cend() const __LC_NOEXCEPT {
        return const_iterator(data() + _Size);
    }

    reverse_iterator rbegin() __LC_NOEXCEPT {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const __LC_NOEXCEPT {
        return const_reverse_iterator(end());
    }

    const_reverse_iterator crbegin() const __LC_NOEXCEPT {
        return const_reverse_iterator(end());
    }

    reverse_iterator rend() __LC_NOEXCEPT {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const __LC_NOEXCEPT {
        return const_reverse_iterator(begin());
    }

    const_reverse_iterator crend() const __LC_NOEXCEPT {
        return const_reverse_iterator(begin());
    }

    __LC_CONSTEXPR bool empty() const __LC_NOEXCEPT {
        return _Size == 0;
    }

    __LC_CONSTEXPR size_type size() const __LC_NOEXCEPT {
        return _Size;
    }

    __LC_CONSTEXPR size_type max_size() const __LC_NOEXCEPT {
        return _Size;
    }

    __LC_CONSTEXPR void fill(const value_type &__value) {
        std::fill_n(data(), _Size, __value);
    }

    __LC_CONSTEXPR void swap(array &__other) __LC_NOEXCEPT {
        std::swap_ranges(data(), data() + _Size, __other.begin());
    }
};

template <class _Tp>
struct array<_Tp, 0> {
    using value_type             = _Tp;
    using size_type              = std::size_t;
    using difference_type        = std::ptrdiff_t;
    using reference              = value_type &;
    using const_reference        = const value_type &;
    using pointer                = value_type *;
    using const_pointer          = const value_type *;
    using iterator               = value_type *;
    using const_iterator         = const value_type *;
    using reverse_iterator       = lc::reverse_iterator<iterator>;
    using const_reverse_iterator = lc::reverse_iterator<const_iterator>;

    _Tp __elems_[1];

    __LC_CONSTEXPR reference at(size_type __pos) {
        std::__throw_out_of_range("array::at");
    }

    __LC_CONSTEXPR const_reference at(size_type __pos) const {
        std::__throw_out_of_range("array::at");
    }

    __LC_CONSTEXPR reference operator[](size_type __pos) {
        std::__throw_out_of_range("array::operator[]");
    }

    __LC_CONSTEXPR const_reference operator[](size_type __pos) const {
        std::__throw_out_of_range("array::operator[]");
    }

    __LC_CONSTEXPR reference front() {
        std::__throw_out_of_range("array::front");
    }

    __LC_CONSTEXPR const_reference front() const {
        std::__throw_out_of_range("array::front");
    }

    __LC_CONSTEXPR reference back() {
        std::__throw_out_of_range("array::back");
    }

    __LC_CONSTEXPR const_reference back() const {
        std::__throw_out_of_range("array::back");
    }

    __LC_CONSTEXPR value_type *data() __LC_NOEXCEPT {
        return nullptr;
    }

    __LC_CONSTEXPR const value_type *data() const __LC_NOEXCEPT {
        return nullptr;
    }

    __LC_CONSTEXPR iterator begin() __LC_NOEXCEPT {
        return iterator(data());
    }

    __LC_CONSTEXPR const_iterator begin() const __LC_NOEXCEPT {
        return const_iterator(data());
    }

    __LC_CONSTEXPR const_iterator cbegin() const __LC_NOEXCEPT {
        return const_iterator(data());
    }

    __LC_CONSTEXPR iterator end() __LC_NOEXCEPT {
        return iterator(data());
    }

    __LC_CONSTEXPR const_iterator end() const __LC_NOEXCEPT {
        return const_iterator(data());
    }

    __LC_CONSTEXPR const_iterator cend() const __LC_NOEXCEPT {
        return const_iterator(data());
    }

    reverse_iterator rbegin() __LC_NOEXCEPT {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const __LC_NOEXCEPT {
        return const_reverse_iterator(end());
    }

    const_reverse_iterator crbegin() const __LC_NOEXCEPT {
        return const_reverse_iterator(end());
    }

    reverse_iterator rend() __LC_NOEXCEPT {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const __LC_NOEXCEPT {
        return const_reverse_iterator(begin());
    }

    const_reverse_iterator crend() const __LC_NOEXCEPT {
        return const_reverse_iterator(begin());
    }

    __LC_CONSTEXPR bool empty() const __LC_NOEXCEPT {
        return true;
    }

    __LC_CONSTEXPR size_type size() const __LC_NOEXCEPT {
        return 0;
    }

    __LC_CONSTEXPR size_type max_size() const __LC_NOEXCEPT {
        return 0;
    }

    __LC_CONSTEXPR void fill(const value_type &__value) {}

    __LC_CONSTEXPR void swap(array &__other) __LC_NOEXCEPT {}
};

template <class _Tp, std::size_t _Size>
inline __LC_CONSTEXPR bool operator==(const array<_Tp, _Size> &__lhs,
                                      const array<_Tp, _Size> &__rhs) {
    return std::equal(__lhs.begin(), __lhs.end(), __rhs.begin(), __rhs.end());
}

template <class _Tp, std::size_t _Size>
inline __LC_CONSTEXPR bool operator!=(const array<_Tp, _Size> &__lhs,
                                      const array<_Tp, _Size> &__rhs) {
    return !(__lhs == __rhs);
}

template <class _Tp, std::size_t _Size>
inline __LC_CONSTEXPR bool operator<(const array<_Tp, _Size> &__lhs,
                                     const array<_Tp, _Size> &__rhs) {
    return std::lexicographical_compare(__lhs.begin(),
                                        __lhs.end(),
                                        __rhs.begin(),
                                        __rhs.end());
}

template <class _Tp, std::size_t _Size>
inline __LC_CONSTEXPR bool operator>(const array<_Tp, _Size> &__lhs,
                                     const array<_Tp, _Size> &__rhs) {
    return __rhs < __lhs;
}

template <class _Tp, std::size_t _Size>
inline __LC_CONSTEXPR bool operator<=(const array<_Tp, _Size> &__lhs,
                                      const array<_Tp, _Size> &__rhs) {
    return !(__rhs < __lhs);
}

template <class _Tp, std::size_t _Size>
inline __LC_CONSTEXPR bool operator>=(const array<_Tp, _Size> &__lhs,
                                      const array<_Tp, _Size> &__rhs) {
    return !(__lhs < __rhs);
}

template <std::size_t _Ip, class _Tp, std::size_t _Size>
inline __LC_CONSTEXPR _Tp &get(array<_Tp, _Size> &__arr) __LC_NOEXCEPT {
    static_assert(_Ip < _Size, "index out of bounds in std::get<>");
    return __arr[_Ip];
}

template <std::size_t _Ip, class _Tp, std::size_t _Size>
inline __LC_CONSTEXPR _Tp &&get(array<_Tp, _Size> &&__arr) __LC_NOEXCEPT {
    static_assert(_Ip < _Size, "index out of bounds in std::get<>");
    return std::move(__arr[_Ip]);
}

template <std::size_t _Ip, class _Tp, std::size_t _Size>
inline __LC_CONSTEXPR const _Tp &get(const array<_Tp, _Size> &__arr)
    __LC_NOEXCEPT {
    static_assert(_Ip < _Size, "index out of bounds in std::get<>");
    return __arr[_Ip];
}

template <std::size_t _Ip, class _Tp, std::size_t _Size>
inline __LC_CONSTEXPR const _Tp &&get(const array<_Tp, _Size> &&__arr)
    __LC_NOEXCEPT {
    static_assert(_Ip < _Size, "index out of bounds in std::get<>");
    return std::move(__arr[_Ip]);
}

#if __LC_CPP_STD_VER < 17
template <class _Tp, std::size_t _Size>
inline __LC_CONSTEXPR void swap(array<_Tp, _Size> &__lhs,
                                array<_Tp, _Size> &__rhs) {
    __lhs.swap(__rhs);
}
#else
template <class _Tp, std::size_t _Size>
inline __LC_CONSTEXPR void swap(array<_Tp, _Size> &__lhs,
                                array<_Tp, _Size> &__rhs)
    __LC_NOEXCEPT_(__LC_NOEXCEPT_(__lhs.swap(__rhs))) {
    __lhs.swap(__rhs);
}
#endif

__LC_NAMESPACE_END

template <class _Tp, std::size_t _Size>
struct std::tuple_size<lc::array<_Tp, _Size>>
    : public std::integral_constant<std::size_t, _Size> {};

template <std::size_t _Ip, class _Tp, std::size_t _Size>
struct std::tuple_element<_Ip, lc::array<_Tp, _Size>> {
    using type = _Tp;
};

#endif  // __LC_CONTAINERS_ARRAY_H
