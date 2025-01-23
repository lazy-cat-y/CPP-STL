

#ifndef ___TYPE_TRAITS_IS_UNBOUNDED_ARRAY_H
#define ___TYPE_TRAITS_IS_UNBOUNDED_ARRAY_H

#include "configs.h"

#if __STL_CPP_VERSION >= 20 || 1

#  include "___type_traits/integral_constant.h"

namespace lc {

#  if __has_builtin(__is_unbounded_array)

template <class _Tp>
struct is_unbounded_array : _bool_constant<__is_unbounded_array(_Tp)> {};

template <class _Tp>
inline constexpr bool is_unbounded_array_v = __is_unbounded_array(_Tp);

#  else   // __has_builtin(__is_unbounded_array)

template <class _Tp>
struct is_unbounded_array : false_type {};

template <class _Tp>
struct is_unbounded_array<_Tp[]> : true_type {};

template <class _Tp>
inline constexpr bool is_unbounded_array_v = is_unbounded_array<_Tp>::value;

#  endif  // __has_builtin(__is_unbounded_array)

}  // namespace lc

#endif  // __STL_CPP_VERSION >= 20

#endif  // ___TYPE_TRAITS_IS_UNBOUNDED_ARRAY_H
