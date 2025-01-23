

#ifndef ___TYPE_TRAITS_IS_MEMBER_OBJECT_POINTER_H
#define ___TYPE_TRAITS_IS_MEMBER_OBJECT_POINTER_H

#include "___type_traits/integral_constant.h"

namespace lc {

#if __has_builtin(__is_member_object_pointer)

template <class _Tp>
struct is_member_object_pointer
    : bool_constant<__is_member_object_pointer(_Tp)> {};

template <class _Tp>
inline constexpr bool is_member_object_pointer_v =
    __is_member_object_pointer(_Tp);

#else  // __has_builtin(__is_member_object_pointer)

#  include "___type_traits/is_member_pointer.h"
#  include "___type_traits/remove_cv.h"

template <class _Tp>
struct is_member_object_pointer
    : bool_constant<__is_member_pointer_t<__remove_cv_t<_Tp>>::__is_obj> {};

template <class _Tp>
inline constexpr bool is_member_object_pointer_v =
    is_member_object_pointer<_Tp>::value;

#endif  // __has_builtin(__is_member_object_pointer)

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_MEMBER_OBJECT_POINTER_H
