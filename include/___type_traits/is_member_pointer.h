

#ifndef ___TYPE_TRAITS_IS_MEMBER_POINTER_H
#define ___TYPE_TRAITS_IS_MEMBER_POINTER_H

#include "___type_traits/integral_constant.h"
#include "___type_traits/is_function.h"
#include "___type_traits/remove_cv.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_member_pointer)

template <class _Tp>
struct is_member_pointer : _bool_constant<__is_member_pointer(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_member_pointer_v = is_member_pointer<_Tp>::value;
#  endif

#else  // __has_builtin(__is_member_pointer)

template <class _Tp>
struct __is_member_pointer_t {
    enum {
        __is_member = false,
        __is_func   = false,
        __is_obj    = false
    };
};

template <class _Tp, class _Up>
struct __is_member_pointer_t<_Tp _Up::*> {
    enum {
        __is_member = true,
        __is_func   = is_function<_Tp>::value,
        __is_obj    = !__is_func
    };
};

template <class _Tp>
struct is_member_pointer
    : _bool_constant<__is_member_pointer_t<__remove_cv_t<_Tp>>::__is_member> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_member_pointer_v = is_member_pointer<_Tp>::value;
#  endif

#endif  // __has_builtin(__is_member_pointer)

}  // namespace lc

#endif
