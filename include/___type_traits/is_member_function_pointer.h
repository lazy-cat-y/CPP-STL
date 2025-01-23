

#ifndef ___TYPE_TRAITS_IS_MEMBER_FUNCTION_POINTER_H
#define ___TYPE_TRAITS_IS_MEMBER_FUNCTION_POINTER_H

#include "___type_traits/integral_constant.h"
namespace lc {

// #if __has_builtin(__is_member_function_pointer)

template <class _Tp>
struct is_member_function_pointer
    : public bool_constant<__is_member_function_pointer(_Tp)> {};

template <class _Tp>
inline constexpr bool is_member_function_pointer_v =
    __is_member_function_pointer(_Tp);

// TODO: Implement is_member_function_pointer without __is_member_function_pointer

}  // namespace lc
#endif  // ___TYPE_TRAITS_IS_MEMBER_FUNCTION_POINTER_H
