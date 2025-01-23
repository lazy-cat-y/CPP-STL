

#ifndef __TYPE_TRAITS_IS_CONST_H
#define __TYPE_TRAITS_IS_CONST_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_const)

template <class _Tp>
struct is_const : _bool_constant<__is_const(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_const_v = __is_const(_Tp);
#  endif

#else  // __has_builtin(__is_const)

template <class _Tp>
struct is_const : false_type {};

template <class _Tp>
struct is_const<const _Tp> : true_type {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_const_v = is_const<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_const)

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_CONST_H
