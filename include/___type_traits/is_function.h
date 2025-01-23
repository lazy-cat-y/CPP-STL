
#ifndef ___TYPE_TRAITS_IS_FUNCTION_H
#define ___TYPE_TRAITS_IS_FUNCTION_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_function)

template <class _Tp>
struct is_function : public integral_constant<bool, __is_function(_Tp)> {};
#else

// TODO: Implement is_function
// template <class _Tp>
// struct is_function
//     : public integral_constant<bool, !(std::is_reference<_Tp>::value ||
//                                        std::is_const<_Tp>::value)> {};

#  error "is_function is not supported"

#endif  // __has_builtin(__is_function)

#if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_function_v = __is_function(_Tp);
#endif

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_FUNCTION_H
