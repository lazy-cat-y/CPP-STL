

#ifndef ___TYPE_TRAITS_IS_ARITHMETIC_H
#define ___TYPE_TRAITS_IS_ARITHMETIC_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/is_floating_point.h"
#include "___type_traits/is_integral.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_arithmetic) && 0

template <class _Tp>
struct is_arithmetic : _bool_constant<__is_arithmetic(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_arithmetic_v = is_arithmetic<_Tp>::value;
#  endif

#else  // __has_builtin(__is_arithmetic)

// f T is an arithmetic type (that is, an integral type or a floating-point
// type) or a cv-qualified version thereof, provides the member constant value
// equal to true. For any other type, value is false.

template <class _Tp>
struct is_arithmetic
    : _bool_constant<is_integral<_Tp>::value || is_floating_point<_Tp>::value> {
};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_arithmetic_v = is_arithmetic<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_arithmetic)

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_ARITHMETIC_H
