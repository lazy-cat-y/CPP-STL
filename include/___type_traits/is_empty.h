

#ifndef __TYPE_TRAITS_IS_EMPTY_H
#define __TYPE_TRAITS_IS_EMPTY_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

template <class _Tp>
struct is_empty : bool_constant<__is_empty(_Tp)> {};

#if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_empty_v = __is_empty(_Tp);
#endif

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_EMPTY_H
