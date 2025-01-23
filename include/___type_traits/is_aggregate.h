

#ifndef __TYPE_TRAITS_IS_AGGREGATE_H
#define __TYPE_TRAITS_IS_AGGREGATE_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

#if __STL_CPP_VERSION >= 17

namespace lc {

template <class _Tp>
struct is_aggregate : _bool_constant<__is_aggregate(_Tp)> {};

template <class _Tp>
inline constexpr bool is_aggregate_v = __is_aggregate(_Tp);

}  // namespace lc

#endif  // __STL_CPP_VERSION >= 17

#endif  // __TYPE_TRAITS_IS_AGGREGATE_H
