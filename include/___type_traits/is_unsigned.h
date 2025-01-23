

#ifndef ___TYPE_TRAITS_IS_UNSIGNED_H
#define ___TYPE_TRAITS_IS_UNSIGNED_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_unsigned)

template <class _Tp>
struct is_unsigned : bool_constant<__is_unsigned(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_unsigned_v = __is_unsigned(_Tp);
#  endif

#else   // __has_builtin(__is_unsigned)

// TODO : Implement is_unsigned

#endif  // __has_builtin(__is_unsigned)

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_UNSIGNED_H
