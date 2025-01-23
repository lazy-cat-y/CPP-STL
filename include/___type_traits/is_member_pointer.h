

#ifndef ___TYPE_TRAITS_IS_MEMBER_POINTER_H
#define ___TYPE_TRAITS_IS_MEMBER_POINTER_H

#if !__has_builtin(__is_member_object_pointer) || \
    !__has_builtin(__is_member_function_pointer)

#  include "___type_traits/is_function.h"

namespace lc {

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

}  // namespace lc

#endif  // !__has_builtin(__is_member_object_pointer) ||
        // !__has_builtin(__is_member_function_pointer)

#endif
