

#ifndef __LC_ITERATOR_DISTANCE_H
#define __LC_ITERATOR_DISTANCE_H

#include "__lc_configs.h"
#include "__lc_iterator/iterator_traits.h"

__LC_NAMESPACE_BEGIN

// If InputIt is not LegacyRandomAccessIterator, the behavior is undefined if
// last is not reachable from first.
template <typename _InputIter>
inline __LC_CONSTEXPR typename iterator_traits<_InputIter>::difference_type
__distance(_InputIter __first, _InputIter __last, input_iterator_tag) {
    typename iterator_traits<_InputIter>::difference_type __r(0);
    for (; __first != __last; ++__first) {
        ++__r;
    }
    return __r;
}

// If InputIt is LegacyRandomAccessIterator, the behavior is undefined if first
// and last are neither reachable from each other.
template <typename _RandIter>
inline __LC_CONSTEXPR typename iterator_traits<_RandIter>::difference_type
__distance(_RandIter __first, _RandIter __last, random_access_iterator_tag) {
    return __last - __first;
}

// InputIt must meet the requirements of LegacyInputIterator. The operation is
// more efficient if InputIt additionally meets the requirements of
// LegacyRandomAccessIterator.

template <typename _InputIter>
inline __LC_CONSTEXPR typename iterator_traits<_InputIter>::difference_type
distance(_InputIter __first, _InputIter __last) {
    return __distance(
        __first,
        __last,
        typename iterator_traits<_InputIter>::iterator_category());
}

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_DISTANCE_H
