

#ifndef ___TYPE_TRAITS_IS_POINTER_H
#define ___TYPE_TRAITS_IS_POINTER_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/remove_cv.h"

namespace lc {

#if __has_builtin(__is_pointer)

template <class _Tp>
struct is_pointer : bool_constant<__is_pointer(_Tp)> {};

template <class _Tp>
inline constexpr bool is_pointer_v = __is_pointer(_Tp);

#else  // __has_builtin(__is_pointer)

template <class _Tp>
struct __is_pointer_t : false_type {};

template <class _Tp>
struct __is_pointer_t<_Tp *> : true_type {};

template <class _Tp>
struct is_pointer : public __is_pointer_t<__remove_cv_t<_Tp>> {};

template <class _Tp>
inline constexpr bool is_pointer_v = is_pointer<_Tp>::value;

#endif

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_POINTER_H
