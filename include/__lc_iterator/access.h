

#ifndef __LC_ITERATOR_ACCESS_H
#define __LC_ITERATOR_ACCESS_H

#include "__lc_configs.h"

__LC_NAMESPACE_BEGIN

#if __LC_CPP_STD_VER >= 11
template <class _C>
inline __LC_CONSTEXPR auto begin(_C &__c) -> decltype(__c.begin()) {
    return __c.begin();
}

template <class _C>
inline __LC_CONSTEXPR auto begin(const _C &__c) -> decltype(__c.begin()) {
    return __c.begin();
}

template <class _Tp, size_t _N>
inline
#  if __LC_CPP_STD_VER >= 14
    __LC_CONSTEXPR
#  endif  // __LC_CPP_STD_VER >= 14
    _Tp *
    begin(_Tp (&__array)[_N])
#  if __LC_CPP_STD_VER >= 14
        __LC_NOEXCEPT
#  endif  // __LC_CPP_STD_VER >= 14
{
    return __array;
}

#  if __LC_CPP_STD_VER >= 14
template <class _C>
inline __LC_CONSTEXPR auto cbegin(const _C &__C)
    __LC_NOEXCEPT_(__LC_NOEXCEPT(begin(__C))) -> decltype(begin(__C)) {
    return begin(__C);
}
#  endif  // __LC_CPP_STD_VER >= 14

template <class _C>
inline __LC_CONSTEXPR auto end(_C &__c) -> decltype(__c.end()) {
    return __c.end();
}

template <class _C>
inline __LC_CONSTEXPR auto end(const _C &__c) -> decltype(__c.end()) {
    return __c.end();
}

template <class _Tp, size_t _N>
inline
#  if __LC_CPP_STD_VER >= 14
    __LC_CONSTEXPR
#  endif  // __LC_CPP_STD_VER >= 14
    _Tp *
    end(_Tp (&__array)[_N])
#  if __LC_CPP_STD_VER >= 14
        __LC_NOEXCEPT
#  endif  // __LC_CPP_STD_VER >= 14
{
    return __array + _N;
}

#  if __LC_CPP_STD_VER >= 14
template <class _C>
inline __LC_CONSTEXPR auto cend(const _C &__c)
    __LC_NOEXCEPT_(__LC_NOEXCEPT(end(__c))) -> decltype(end(__c)) {
    return end(__c);
}
#  endif  // __LC_CPP_STD_VER >= 14

#endif    // __LC_CPP_STD_VER >= 11

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_ACCESS_H
