

#ifndef ___TYPE_TRAITS_IS_SCALAR_H
#define ___TYPE_TRAITS_IS_SCALAR_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/is_arithmetic.h"
#include "___type_traits/is_enum.h"
#include "___type_traits/is_member_pointer.h"
#include "___type_traits/is_null_pointer.h"
#include "___type_traits/is_pointer.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_scalar)

template <class _Tp>
struct is_scalar : _bool_constant<__is_scalar(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_scalar_v = is_scalar<_Tp>::value;
#  endif

#else  // __has_builtin(__is_scalar)

// If T is a scalar type, provides the member constant value equal true. For any
// other type, value is false. That is arithmetic type, enumeration type,
// pointer type, member pointer type, or null pointer type

template <class _Tp>
struct is_scalar
    : _bool_constant<is_arithmetic<_Tp>::value || is_enum<_Tp>::value ||
                     is_pointer<_Tp>::value || is_member_pointer<_Tp>::value ||
                     is_null_pointer<_Tp>::value> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_scalar_v = is_scalar<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_scalar)

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_SCALAR_H
