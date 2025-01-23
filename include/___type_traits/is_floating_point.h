

#ifndef ___TYPE_TRAITS_IS_FLOATING_POINT_H
#define ___TYPE_TRAITS_IS_FLOATING_POINT_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/remove_cv.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_floating_point)

template <class _Tp>
struct is_floating_point : _bool_constant<__is_floating_point(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_floating_point_v = is_floating_point<_Tp>::value;
#  endif

#else  // __has_builtin(__is_floating_point)

// clang-format off
template <class _Tp> struct __is_floating_point_t              : public false_type {};
template <>          struct __is_floating_point_t<float>        : public true_type {};
template <>          struct __is_floating_point_t<double>      : public true_type {};
template <>          struct __is_floating_point_t<long double> : public true_type {};

// clang-format on

template <class _Tp>
struct is_floating_point : public __is_floating_point_t<__remove_cv_t<_Tp>> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_floating_point_v = is_floating_point<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_floating_point)
}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_FLOATING_POINT_H
