

#ifndef __TYPE_TRAITS_IS_ABSTRACT_H
#define __TYPE_TRAITS_IS_ABSTRACT_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

template <class _Tp>
struct is_abstract : bool_constant<__is_abstract(_Tp)> {};

#if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_abstract_v = __is_abstract(_Tp);
#endif

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_ABSTRACT_H
