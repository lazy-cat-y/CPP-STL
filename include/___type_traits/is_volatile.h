
#ifndef ___TYPE_TRAITS_IS_VOLATILE_H
#define ___TYPE_TRAITS_IS_VOLATILE_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_volatile)

template <class _Tp>
struct is_volatile : _bool_constant<__is_volatile(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_volatile_v = __is_volatile(_Tp);
#  endif

#else  // __has_builtin(__is_volatile)

template <class _Tp>
struct is_volatile : false_type {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
struct is_volatile<volatile _Tp> : true_type {};
#  endif

#endif  // __has_builtin(__is_volatile)

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_VOLATILE_H
