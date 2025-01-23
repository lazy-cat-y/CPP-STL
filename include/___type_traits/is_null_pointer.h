

#ifndef __TYPE_TRAITS_IS_NULL_POINTER_H
#define __TYPE_TRAITS_IS_NULL_POINTER_H

#include <cstddef>

#include "___type_traits/remove_cv.h"
#include "configs.h"
#include "integral_constant.h"

namespace lc {

template <class _Tp>
struct __is_nullptr_t_impl : public false_type {};
template <>
struct __is_nullptr_t_impl<nullptr_t> : public true_type {};

template <class _Tp>
struct __is_nullptr_t : public __is_nullptr_t_impl<lc::__remove_cv_t<_Tp>> {};

#if __STL_CPP_VERSION >= 14
template <class _Tp>
struct is_null_pointer : public __is_nullptr_t_impl<lc::__remove_cv_t<_Tp>> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_null_pointer_v = is_null_pointer<_Tp>::value;
#  endif  // __STL_CPP_VERSION >= 17

#endif    // __STL_CPP_VERSION >= 14

}  // namespace lc

#endif
