

#ifndef ___TYPE_TRAITS_IS_FUNDAMENTAL_H
#define ___TYPE_TRAITS_IS_FUNDAMENTAL_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/is_arithmetic.h"
#include "___type_traits/is_null_pointer.h"
#include "___type_traits/is_void.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_fundamental) && 0

template <class _Tp>
struct is_fundamental : _bool_constant<__is_fundamental(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_fundamental_v = is_fundamental<_Tp>::value;
#  endif

#else  // __has_builtin(__is_fundamental)

// If T is a fundamental type (that is, arithmetic type, void, or nullptr_t),
// provides the member constant value equal true. For any other type, value is
// false.

template <class _Tp>
struct is_fundamental
    : _bool_constant<is_arithmetic<_Tp>::value || is_void<_Tp>::value ||
                     is_null_pointer<_Tp>::value> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_fundamental_v = is_fundamental<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_fundamental)

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_FUNDAMENTAL_H
