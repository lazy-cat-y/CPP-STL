

#ifndef __TYPE_TRAITS_IS_STANDARD_LAYOUT_H
#define __TYPE_TRAITS_IS_STANDARD_LAYOUT_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

template <class _Tp>
struct is_standard_layout : bool_constant<__is_standard_layout(_Tp)> {};

#if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_standard_layout_v = __is_standard_layout(_Tp);
#endif

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_STANDARD_LAYOUT_H
