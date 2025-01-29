

#ifndef __LC_ITERATOR_DATA_H
#define __LC_ITERATOR_DATA_H

#include "__lc_configs.h"

#if __LC_CPP_STD_VER >= 17

__LC_NAMESPACE_BEGIN

template <class _C>
__LC_CONSTEXPR auto data(_C &__c) -> decltype(__c.data()) {
    return __c.data();
}

template <class _C>
__LC_CONSTEXPR auto data(const _C &__c) -> decltype(__c.data()) {
    return __c.data();
}

template <class _Tp, size_t _N>
__LC_CONSTEXPR _Tp *data(_Tp (&__array)[_N]) __LC_NOEXCEPT {
    return __array;
}

template <class _E>
__LC_CONSTEXPR const _E *data(std::initializer_list<_E> __il) __LC_NOEXCEPT {
    return __il.begin();
}

__LC_NAMESPACE_END

#endif  // __LC_CPP_STD_VER >= 17

#endif  // __LC_ITERATOR_DATA_H
