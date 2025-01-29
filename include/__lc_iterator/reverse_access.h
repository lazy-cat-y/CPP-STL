

#ifndef __LC_ITERATOR_REVERSE_ACCESS_H
#define __LC_ITERATOR_REVERSE_ACCESS_H

#include "__lc_configs.h"
#include "__lc_iterator/reverse_iterator.h"

__LC_NAMESPACE_BEGIN

#if __LC_CPP_STD_VER >= 14

template <class _C>
__LC_CONSTEXPR auto rbegin(_C &__c) -> decltype(__c.rbegin()) {
    return __c.rbegin();
}

template <class _C>
__LC_CONSTEXPR auto rbegin(const _C &__c) -> decltype(__c.rbegin()) {
    return __c.rbegin();
}

template <class _Tp, size_t _N>
__LC_CONSTEXPR reverse_iterator<_Tp *> rbegin(_Tp (&__array)[_N])
    __LC_NOEXCEPT {
    return reverse_iterator<_Tp *>(__array + _N);
}

template <class _Tp>
__LC_CONSTEXPR reverse_iterator<const _Tp *> rbegin(
    std::initializer_list<_Tp> __il) __LC_NOEXCEPT {
    return reverse_iterator<const _Tp *>(__il.end());
}

template <class _C>
__LC_CONSTEXPR auto crbegin(const _C &__c) -> decltype(rbegin(__c)) {
    return rbegin(__c);
}

template <class _C>
__LC_CONSTEXPR auto rend(_C &__c) -> decltype(__c.rend()) {
    return __c.rend();
}

template <class _C>
__LC_CONSTEXPR auto rend(const _C &__c) -> decltype(__c.rend()) {
    return __c.rend();
}

template <class _Tp, size_t _N>
__LC_CONSTEXPR reverse_iterator<_Tp *> rend(_Tp (&__array)[_N]) __LC_NOEXCEPT {
    return reverse_iterator<_Tp *>(__array);
}

template <class _Tp>
__LC_CONSTEXPR reverse_iterator<const _Tp *> rend(
    std::initializer_list<_Tp> __il) __LC_NOEXCEPT {
    return reverse_iterator<const _Tp *>(__il.begin());
}

template <class _C>
__LC_CONSTEXPR auto crend(const _C &__c) -> decltype(rend(__c)) {
    return rend(__c);
}

#endif  // __LC_CPP_STD_VER >= 14

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_REVERSE_ACCESS_H
