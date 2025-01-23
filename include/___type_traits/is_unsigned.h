

#ifndef ___TYPE_TRAITS_IS_UNSIGNED_H
#define ___TYPE_TRAITS_IS_UNSIGNED_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/is_arithmetic.h"
#include "___type_traits/is_integral.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_unsigned)

template <class _Tp>
struct is_unsigned : _bool_constant<__is_unsigned(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_unsigned_v = __is_unsigned(_Tp);
#  endif

#else  // __has_builtin(__is_unsigned)

template <class _Tp, bool = is_integral<_Tp>::value>
struct __is_unsigned_t_impl : public _bool_constant<(_Tp(0) < _Tp(-1))> {};

template <class _Tp>
struct __is_unsigned_t_impl<_Tp, false> : public false_type {};

template <class _Tp, bool = is_arithmetic<_Tp>::value>
struct __is_unsigned_t : public __is_unsigned_t_impl<_Tp> {};

template <class _Tp>
struct __is_unsigned_t<_Tp, false> : public false_type {};

template <class _Tp>
struct is_unsigned : public __is_unsigned_t<_Tp> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_unsigned_v = is_unsigned<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_unsigned)

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_UNSIGNED_H
