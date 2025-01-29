

#ifndef __LC_ITERATOR_ADVANCE_H
#define __LC_ITERATOR_ADVANCE_H

#include <__utility/convert_to_integral.h>

#include <__config>
#include <type_traits>
#include <utility>

#include "__lc_configs.h"
#include "__lc_iterator/iterator_traits.h"

__LC_NAMESPACE_BEGIN

template <class _InputIter>
__LC_CONSTEXPR void __advance(
    _InputIter                                           &__iter,
    typename iterator_traits<_InputIter>::difference_type __n,
    input_iterator_tag) {
    for (; __n > 0; --__n) {
        ++__iter;
    }
}

template <class _BiDirIter>
__LC_CONSTEXPR void __advance(
    _BiDirIter                                           &__iter,
    typename iterator_traits<_BiDirIter>::difference_type __n,
    bidirectional_iterator_tag) {
    if (__n >= 0) {
        for (; __n > 0; --__n) {
            ++__iter;
        }
    } else {
        for (; __n < 0; ++__n) {
            --__iter;
        }
    }
}

template <class _RandIter>
__LC_CONSTEXPR void __advance(
    _RandIter &__iter, typename iterator_traits<_RandIter>::difference_type __n,
    random_access_iterator_tag) {
    __iter += __n;
}

template <typename _InputIter, typename _Distance,
          // Through this way, the template constraint is only allowed to be
          // instantiated when _Distance can be converted by
          // std::__convert_to_integral to an integral type.
          class = std::enable_if_t<
              std::is_integral<decltype(std::__convert_to_integral(
                  std::declval<_Distance>()))>::value>>
__LC_CONSTEXPR void advance(_InputIter &__iter, _Distance __n) {
    typedef typename iterator_traits<_InputIter>::difference_type _Difference;

    _Difference __diff =
        static_cast<_Difference>(std::__convert_to_integral(__n));
    // If n is negative, the iterator is decremented. In this case, InputIt must
    // meet the requirements of LegacyBidirectionalIterator, otherwise the
    // behavior is undefined.
    __LC_ASSERT(
        __diff >= 0 || __has_bidirectional_iterator_category<_InputIter>::value,
        "Attempt to advance(it, n) with negative n on a non-bidirectional iterator");

    __advance(__iter,
              __diff,
              typename iterator_traits<_InputIter>::iterator_category());
}

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_ADVANCE_H
