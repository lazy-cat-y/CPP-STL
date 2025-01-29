

#ifndef __LC_ITERATOR_SIZE_H
#define __LC_ITERATOR_SIZE_H

#include "__lc_configs.h"

#if __LC_CPP_STD_VER >= 17

__LC_NAMESPACE_BEGIN

template <class _C>
__LC_CONSTEXPR auto size(const _C &__c) -> decltype(__c.size()) {
    return __c.size();
}

template <class _Tp, size_t _N>
__LC_CONSTEXPR std::size_t size(const _Tp (&__array)[_N]) __LC_NOEXCEPT {
    return _N;
}

#endif  // __LC_CPP_STD_VER >= 17

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_SIZE_H
