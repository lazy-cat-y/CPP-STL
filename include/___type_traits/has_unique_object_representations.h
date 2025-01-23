

#ifndef __TYPE_TRAITS_HAS_UNIQUE_OBJECT_REPRESENTATIONS_H
#define __TYPE_TRAITS_HAS_UNIQUE_OBJECT_REPRESENTATIONS_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

#if __STL_CPP_VERSION >= 17

namespace lc {

template <class _Tp>
struct has_unique_object_representations
    : _bool_constant<__has_unique_object_representations(_Tp)> {};

template <class _Tp>
inline constexpr bool has_unique_object_representations_v =
    __has_unique_object_representations(_Tp);

}  // namespace lc

#endif  // __STL_CPP_VERSION

#endif  // __TYPE_TRAITS_HAS_UNIQUE_OBJECT_REPRESENTATIONS_H
