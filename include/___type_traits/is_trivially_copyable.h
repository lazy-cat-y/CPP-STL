

#ifndef __TYPE_TRAITS_IS_TRIVIALLY_COPYABLE_H
#define __TYPE_TRAITS_IS_TRIVIALLY_COPYABLE_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

template <class _Tp>
struct is_trivially_copyable : _bool_constant<__is_trivially_copyable(_Tp)> {};

#if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_trivially_copyable_v = __is_trivially_copyable(_Tp);
#endif

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_TRIVIALLY_COPYABLE_H
