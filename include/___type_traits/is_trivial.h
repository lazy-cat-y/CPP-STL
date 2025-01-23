

#ifndef __TYPE_TRAITS_IS_TRIVIAL_H
#define __TYPE_TRAITS_IS_TRIVIAL_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

template <class _Tp>
struct is_trivial : bool_constant<__is_trivial(_Tp)> {};

#if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_trivial_v = __is_trivial(_Tp);
#endif

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_TRIVIAL_H
