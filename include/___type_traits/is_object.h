

#ifndef ___TYPE_TRAITS_IS_OBJECT_H
#define ___TYPE_TRAITS_IS_OBJECT_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/is_array.h"
#include "___type_traits/is_class.h"
#include "___type_traits/is_scalar.h"
#include "___type_traits/is_union.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_object)

template <class _Tp>
struct is_object : _bool_constant<__is_object(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_object_v = is_object<_Tp>::value;
#  endif

#else  // __has_builtin(__is_object)

// If T is an object type (that is any possibly cv-qualified type other than
// function, reference, or void types), provides the member constant value equal
// true. For any other type, value is false. That is, integral constant, scalar
// type, array type, union type, class type.

template <class _Tp>
struct is_object
    : _bool_constant<is_scalar<_Tp>::value || is_array<_Tp>::value ||
                     is_union<_Tp>::value || is_class<_Tp>::value> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_object_v = is_object<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_object)

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_OBJECT_H
