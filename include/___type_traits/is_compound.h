

#ifndef ___TYPE_TRAITS_IS_COMPOUND_H
#define ___TYPE_TRAITS_IS_COMPOUND_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/is_fundamental.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_compound)

template <class _Tp>
struct is_compound : _bool_constant<__is_compound(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_compound_v = is_compound<_Tp>::value;
#  endif

#else  // __has_builtin(__is_compound)

// If T is a compound type (that is, array, function, object pointer, function
// pointer, member object pointer, member function pointer, reference, class,
// union, or enumeration, including any cv-qualified variants), provides the
// member constant value equal true. For any other type, value is false.
// ! is_fundamental<T>::value

template <class _Tp>
struct is_compound : _bool_constant<!is_fundamental<_Tp>::value> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_compound_v = is_compound<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_compound)

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_COMPOUND_H
