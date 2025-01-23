

#ifndef __TYPE_TRAITS_IS_SIGNED_H
#define __TYPE_TRAITS_IS_SIGNED_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/is_arithmetic.h"
#include "___type_traits/is_integral.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_signed)

template <class _Tp>
struct is_signed : _bool_constant<__is_signed(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_signed_v = __is_signed(_Tp);
#  endif

#else  // __has_builtin(__is_signed)

template <class _Tp, bool = is_integral<_Tp>::value>
struct __is_signed_t_impl : public _bool_constant<(_Tp(-1) < _Tp(0))> {};

template <class _Tp>
struct __is_signed_t_impl<_Tp, false> : public true_type {};

template <class _Tp, bool = is_arithmetic<_Tp>::value>
struct __is_signed_t : public __is_signed_t_impl<_Tp> {};

template <class _Tp>
struct __is_signed_t<_Tp, false> : public false_type {};

template <class _Tp>
struct is_signed : public __is_signed_t<_Tp> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_signed_v = is_signed<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_signed)

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_SIGNED_H
