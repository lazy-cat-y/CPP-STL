

#ifndef __LC_ITERATOR_EMPTY_H
#define __LC_ITERATOR_EMPTY_H

#include "__lc_configs.h"

__LC_NAMESPACE_BEGIN

template <class _C>
__LC_CONSTEXPR auto empty(const _C &__c) -> decltype(__c.empty()) {
    return __c.empty();
}

template <class _Tp, size_t _N>
__LC_CONSTEXPR bool empty(const _Tp (&__array)[_N]) __LC_NOEXCEPT {
    return _N == 0;
}

template <class _E>
__LC_CONSTEXPR bool empty(std::initializer_list<_E> __il) __LC_NOEXCEPT {
    return __il.size() == 0;
}

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_EMPTY_H
