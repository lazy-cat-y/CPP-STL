

#ifndef ___TYPE_TRAITS_IS_POINTER_H
#define ___TYPE_TRAITS_IS_POINTER_H

#include "___type_traits/integral_constant.h"
namespace lc {

#if __has_builtin(__is_pointer)

template <class _Tp>
struct is_pointer : bool_constant<__is_pointer(_Tp)> {};

template <class _Tp>
inline constexpr bool is_pointer_v = __is_pointer(_Tp);

#else  // __has_builtin(__is_pointer)

#  error "is_pointer is not supported"
// TODO : Implement is_pointer
// __strong, __weak, __autoreleasing, __unsafe_unretained

#endif

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_POINTER_H
