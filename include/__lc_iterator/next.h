

#ifndef __LC_ITERATOR_NEXT_H
#define __LC_ITERATOR_NEXT_H

#include "__lc_configs.h"
#include "__lc_iterator/advance.h"
#include "__lc_iterator/iterator_traits.h"

__LC_NAMESPACE_BEGIN

template <
    typename _InputIter,
    std::enable_if_t<__has_input_iterator_category<_InputIter>::value, int> = 0>
inline __LC_CONSTEXPR _InputIter
next(_InputIter                                            __it,
     typename iterator_traits<_InputIter>::difference_type __n = 1) {
    __LC_ASSERT(
        __n >= 0 || __has_bidirectional_iterator_category<_InputIter>::value,
        "Attempt to next(it, n) with negative n on a non-bidirectional iterator");
    advance(__it, __n);
    return __it;
}

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_NEXT_H
