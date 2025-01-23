

#ifndef ___TYPE_TRAITS_IS_MEMBER_FUNCTION_POINTER_H
#define ___TYPE_TRAITS_IS_MEMBER_FUNCTION_POINTER_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/is_member_pointer.h"
#include "___type_traits/remove_const.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_member_function_pointer)

template <class _Tp>
struct is_member_function_pointer
    : public _bool_constant<__is_member_function_pointer(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_member_function_pointer_v =
    __is_member_function_pointer(_Tp);
#  endif

#else  // __has_builtin(__is_member_function_pointer)
template <class _Tp>
struct is_member_function_pointer
    : public bool_constant<
          __is_member_pointer_t<__remove_const_t<_Tp>>::__is_func> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_member_function_pointer_v =
    is_member_function_pointer<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_member_function_pointer)

}  // namespace lc
#endif  // ___TYPE_TRAITS_IS_MEMBER_FUNCTION_POINTER_H
