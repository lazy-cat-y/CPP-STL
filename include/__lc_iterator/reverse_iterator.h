

#ifndef __LC_ITERATOR_REVERSE_ITERATOR_H
#define __LC_ITERATOR_REVERSE_ITERATOR_H

#include <__lc_configs.h>

#include <memory>
#include <type_traits>

#include "__lc_iterator/iterator.h"
#include "__lc_iterator/iterator_traits.h"

__LC_NAMESPACE_BEGIN

template <class _Iter>
class reverse_iterator
    : public iterator<typename iterator_traits<_Iter>::iterator_category,
                      typename iterator_traits<_Iter>::value_type,
                      typename iterator_traits<_Iter>::difference_type,
                      typename iterator_traits<_Iter>::pointer,
                      typename iterator_traits<_Iter>::reference> {
public:
    using iterator_type = _Iter;
    using iterator_category =
        typename iterator_traits<_Iter>::iterator_category;
    using value_type      = typename iterator_traits<_Iter>::value_type;
    using difference_type = typename iterator_traits<_Iter>::difference_type;
    using pointer         = typename iterator_traits<_Iter>::pointer;
    using reference       = typename iterator_traits<_Iter>::reference;

public:

    // Constructors
    __LC_CONSTEXPR reverse_iterator() : __current() {}

    __LC_EXPLICIT __LC_CONSTEXPR reverse_iterator(_Iter __x) : __current(__x) {}

    // This overload participates in overload resolution only if
    // std::is_same_v<U, Iter> is false and std::convertible_to<const U&, Iter>
    // is modeled.
    template <class _Up, class = std::enable_if_t<
                             !std::is_same<_Up, _Iter>::value &&
                             std::is_convertible<_Up const &, _Iter>::value>>
    __LC_CONSTEXPR reverse_iterator(const reverse_iterator<_Up> &__u) :
        __current(__u.base()) {}

    // This overload participates in overload resolution only if
    // std::is_same_v<U, Iter> is false and both std::convertible_to<const U&,
    // Iter> and std::assignable_from<Iter&, const U&> are modeled.
    template <class _Up, class = std::enable_if_t<
                             !std::is_same<_Up, _Iter>::value &&
                             std::is_convertible<_Up const &, _Iter>::value &&
                             std::is_assignable<_Iter &, _Up const &>::value>>
    __LC_CONSTEXPR reverse_iterator &operator=(
        const reverse_iterator<_Up> &__u) {
        __current = __u.base();
        return *this;
    }

    __LC_CONSTEXPR _Iter base() const {
        return __current;
    }

    __LC_CONSTEXPR reference operator*() const {
        _Iter __tmp = __current;
        return *--__tmp;
    }

    __LC_CONSTEXPR pointer operator->() const {
#if __LC_CPP_STD_VER <= 11
        return &(operator*());
#else
        return std::addressof(operator*());
#endif
    }

    __LC_CONSTEXPR reference operator[](difference_type __n) const {
        return __current[-__n - 1];
    }

    __LC_CONSTEXPR reverse_iterator &operator++() {
        --__current;
        return *this;
    }

    __LC_CONSTEXPR reverse_iterator &operator--() {
        ++__current;
        return *this;
    }

    __LC_CONSTEXPR reverse_iterator operator++(int) {
        reverse_iterator __tmp = *this;
        --__current;
        return __tmp;
    }

    __LC_CONSTEXPR reverse_iterator operator--(int) {
        reverse_iterator __tmp = *this;
        ++__current;
        return __tmp;
    }

    __LC_CONSTEXPR reverse_iterator operator+(difference_type __n) const {
        return reverse_iterator(__current - __n);
    }

    __LC_CONSTEXPR reverse_iterator operator-(difference_type __n) const {
        return reverse_iterator(__current + __n);
    }

    __LC_CONSTEXPR reverse_iterator &operator+=(difference_type __n) {
        __current -= __n;
        return *this;
    }

    __LC_CONSTEXPR reverse_iterator &operator-=(difference_type __n) {
        __current += __n;
        return *this;
    }

protected:
    _Iter __current;
};

template <class _Iter1, class _Iter2>
inline __LC_CONSTEXPR bool operator==(
    const reverse_iterator<_Iter1> &__lhs,
    const reverse_iterator<_Iter2> &__rhs) {
    return __lhs.base() == __rhs.base();
}

template <class _Iter1, class _Iter2>
bool operator!=(const reverse_iterator<_Iter1> &__lhs,
                const reverse_iterator<_Iter2> &__rhs) {
    return __lhs.base() != __rhs.base();
}

template <class _Iter1, class _Iter2>
bool operator<(const reverse_iterator<_Iter1> &__lhs,
               const reverse_iterator<_Iter2> &__rhs) {
    return __lhs.base() > __rhs.base();
}

template <class _Iter1, class _Iter2>
bool operator<=(const reverse_iterator<_Iter1> &__lhs,
                const reverse_iterator<_Iter2> &__rhs) {
    return __lhs.base() >= __rhs.base();
}

template <class _Iter1, class _Iter2>
bool operator>(const reverse_iterator<_Iter1> &__lhs,
               const reverse_iterator<_Iter2> &__rhs) {
    return __lhs.base() < __rhs.base();
}

template <class _Iter1, class _Iter2>
bool operator>=(const reverse_iterator<_Iter1> &__lhs,
                const reverse_iterator<_Iter2> &__rhs) {
    return __lhs.base() <= __rhs.base();
}

template <class _Iter>
reverse_iterator<_Iter> operator+(
    typename reverse_iterator<_Iter>::difference_type __n,
    const reverse_iterator<_Iter>                    &__it) {
    return reverse_iterator<_Iter>(__it.base() - __n);
}

template <class _Iter1, class _Iter2>
#if __LC_CPP_STD_VER < 11
typename reverse_iterator<_Iter1>::difference_type operator-(
    const reverse_iterator<_Iter1> &__lhs,
    const reverse_iterator<_Iter2> &__rhs) {
    return __rhs.base() - __lhs.base();
}
#else   // __LC_CPP_STD_VER >= 11
auto operator-(const reverse_iterator<_Iter1> &__lhs,
               const reverse_iterator<_Iter2> &__rhs)
    -> decltype(__rhs.base() - __lhs.base()) {
    return __rhs.base() - __lhs.base();
}
#endif  // __LC_CPP_STD_VER

#if __LC_CPP_STD_VER >= 14
template <class _Iter>
reverse_iterator<_Iter> make_reverse_iterator(_Iter __i) {
    return reverse_iterator<_Iter>(__i);
}
#endif  // __LC_CPP_STD_VER >= 14

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_REVERSE_ITERATOR_H
