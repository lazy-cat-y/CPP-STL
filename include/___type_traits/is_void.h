

#ifndef __TYPE_TRAITS_IS_VOID_H
#define __TYPE_TRAITS_IS_VOID_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/is_same.h"
#include "___type_traits/remove_cv.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_void)
template <class _Tp>
struct is_void : _bool_constant<__is_void(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_void_v = __is_void(_Tp);
#  endif

#else  // __has_builtin(__is_void)

template <class _Tp>
struct is_void : public is_same<__remove_cv_t<_Tp>, void> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_void_v = is_void<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_void)

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_VOID_H
