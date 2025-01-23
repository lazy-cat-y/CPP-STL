
#ifndef ___TYPE_TRAITS_IS_FUNCTION_H
#define ___TYPE_TRAITS_IS_FUNCTION_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/is_const.h"
#include "___type_traits/is_reference.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_function)

template <class _Tp>
struct is_function : public integral_constant<bool, __is_function(_Tp)> {};

#else   // __has_builtin(__is_function)

template <class _Tp>
struct is_function : public _bool_constant<!(is_reference<_Tp>::value ||
                                             is_const<const _Tp>::value)> {};

#endif  // __has_builtin(__is_function)

#if _LIBCPP_STD_VER >= 17
template <class _Tp>
inline constexpr bool is_function_v = is_function<_Tp>::value;
#endif

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_FUNCTION_H
