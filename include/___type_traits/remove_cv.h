

#ifndef __TYPE_TRAITS_REMOVE_CV_H
#define __TYPE_TRAITS_REMOVE_CV_H

#include "___type_traits/remove_const.h"
#include "___type_traits/remove_volatile.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__remove_cv) && !defined(_LIBCPP_COMPILER_GCC)

template <class _Tp>
struct remove_cv {
    using type __STL_NODEBUG = __remove_cv(_Tp);
};

template <class _Tp>
using __remove_cv_t = __remove_cv(_Tp);

#else   // __has_builtin(__remove_cv) && !defined(_LIBCPP_COMPILER_GCC)

template <class _Tp>
struct remove_cv {
    typedef __remove_volatile_t<__remove_const_t<_Tp>> type;
};

template <class _Tp>
using __remove_cv_t = __remove_volatile_t<__remove_const_t<_Tp>>;

#endif  // __has_builtin(__remove_cv) && !defined(_LIBCPP_COMPILER_GCC)

#if __STL_CPP_VERSION >= 17
template <class _Tp>
using remove_cv_t = __remove_cv_t<_Tp>;
#endif

}  // namespace lc

#endif
