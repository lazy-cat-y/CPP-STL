

#ifndef __TYPE_TRAITS_IS_POLYMORPHIC_H
#define __TYPE_TRAITS_IS_POLYMORPHIC_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

template <class _Tp>
struct is_polymorphic : bool_constant<__is_polymorphic(_Tp)> {};

#if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_polymorphic_v = __is_polymorphic(_Tp);
#endif

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_POLYMORPHIC_H
