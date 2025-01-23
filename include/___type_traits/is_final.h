

#ifndef __TYPE_TRAITS_IS_FINAL_H
#define __TYPE_TRAITS_IS_FINAL_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

template <class _Tp>
struct is_final : public integral_constant<bool, __is_final(_Tp)> {};

#if __STL_CPP_VERSION >= 17
template <class _Tp>
constexpr bool is_final_v = is_final<_Tp>::value;
#endif

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_FINAL_H
