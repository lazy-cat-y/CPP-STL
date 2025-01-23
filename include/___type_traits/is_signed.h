

#ifndef __TYPE_TRAITS_IS_SIGNED_H
#define __TYPE_TRAITS_IS_SIGNED_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_signed)

template <class _Tp>
struct is_signed : bool_constant<__is_signed(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_signed_v = __is_signed(_Tp);
#  endif

#else   // __has_builtin(__is_signed)

// TODO : Implement is_signed

#endif  // __has_builtin(__is_signed)

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_SIGNED_H
