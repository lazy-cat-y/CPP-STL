

#ifndef ___TYPE_TRAITS_IS_BOUNDED_ARRAY_H
#define ___TYPE_TRAITS_IS_BOUNDED_ARRAY_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

#if __STL_CPP_VERSION >= 20

namespace lc {

#  if __has_builtin(__is_bounded_array)

template <class _Tp>
struct is_bounded_array : bool_constant<__is_bounded_array(_Tp)> {};

template <class _Tp>
inline constexpr bool is_bounded_array_v = __is_bounded_array(_Tp);

#  else  // __has_builtin(__is_bounded_array)

#    include <cstddef>

template <class _Tp>
struct is_bounded_array : false_type {};

template <class _Tp, std::size_t _Bound>
struct is_bounded_array<_Tp[_Bound]> : true_type {};

template <class _Tp>
inline constexpr bool is_bounded_array_v = is_bounded_array<_Tp>::value;

#  endif  // __has_builtin(__is_bounded_array)

}  // namespace lc

#endif  // __STL_CPP_VERSION >= 20

#endif  // ___TYPE_TRAITS_IS_BOUNDED_ARRAY_H
