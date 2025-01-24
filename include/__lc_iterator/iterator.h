

#ifndef __LC_ITERATOR_ITERATOR_H
#define __LC_ITERATOR_ITERATOR_H

#include <__lc_configs.h>

#include <cstddef>

__LC_NAMESPACE_BEGIN

template <class _Category, class _Tp, class _Distance = std::ptrdiff_t,
          class _Pointer = _Tp *, class _Reference = _Tp &>
class iterator {
    using value_type        = _Tp;
    using difference_type   = _Distance;
    using pointer           = _Pointer;
    using reference         = _Reference;
    using iterator_category = _Category;
};

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_ITERATOR_H
