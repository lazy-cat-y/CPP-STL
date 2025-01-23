

#ifndef __TYPE_TRAITS_IS_POD_H
#define __TYPE_TRAITS_IS_POD_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

template <class _Tp>
struct is_pod : _bool_constant<__is_pod(_Tp)> {};

#if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_pod_v = __is_pod(_Tp);
#endif

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_POD_H
