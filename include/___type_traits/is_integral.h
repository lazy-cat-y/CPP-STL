

#ifndef ___TYPE_TRAITS_IS_INTEGRAL_H
#define ___TYPE_TRAITS_IS_INTEGRAL_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/remove_cv.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_integral)

template <class _Tp>
struct is_integral : _bool_constant<__is_integral(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_integral_v = is_integral<_Tp>::value;
#  endif

#else  // __has_builtin(__is_integral)

// clang-format off
template<class _Tp>     struct __is_integral_t                      : false_type {};
template<>              struct __is_integral_t<bool>                : true_type {};
template<>              struct __is_integral_t<char>                : true_type {};
template<>              struct __is_integral_t<signed char>         : true_type {};
template<>              struct __is_integral_t<unsigned char>       : true_type {};
#ifndef _LIBCPP_HAS_NO_WIDE_CHARACTERS
template<>              struct __is_integral_t<wchar_t>             : true_type {};
#endif // _LIBCPP_HAS_NO_WIDE_CHARACTERS
#ifndef _LIBCPP_HAS_NO_CHAR8_T
template<>              struct __is_integral_t<char8_t>             : true_type {};
#endif // _LIBCPP_HAS_NO_CHAR8_T
template<>              struct __is_integral_t<char16_t>            : true_type {};
template<>              struct __is_integral_t<char32_t>            : true_type {};
template<>              struct __is_integral_t<short>               : true_type {};
template<>              struct __is_integral_t<unsigned short>      : true_type {};
template<>              struct __is_integral_t<int>                 : true_type {};
template<>              struct __is_integral_t<unsigned int>        : true_type {};
template<>              struct __is_integral_t<long>                : true_type {};
template<>              struct __is_integral_t<unsigned long>       : true_type {};
template<>              struct __is_integral_t<long long>           : true_type {};
template<>              struct __is_integral_t<unsigned long long>  : true_type {};
#ifndef _LIBCPP_HAS_NO_INT128
template<>              struct __is_integral_t<__int128_t>          : true_type {};
template<>              struct __is_integral_t<__uint128_t>         : true_type {};
#endif // _LIBCPP_HAS_NO_INT128
// clang-format on

template <class _Tp>
struct is_integral : public __is_integral_t<__remove_cv_t<_Tp>> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_integral_v = is_integral<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_integral)

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_INTEGRAL_H
