
#ifndef ___TYPE_TRAITS_IS_UNION_H
#define ___TYPE_TRAITS_IS_UNION_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

template <class _Tp>
struct is_union : public integral_constant<bool, __is_union(_Tp)> {};

#if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_union_v = __is_union(_Tp);
#endif

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_UNION_H
