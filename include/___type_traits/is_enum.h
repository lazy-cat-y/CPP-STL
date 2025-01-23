

#ifndef __TYPE_TRAITS_IS_ENUM_H
#define __TYPE_TRAITS_IS_ENUM_H

#include "___type_traits/integral_constant.h"

namespace lc {

template<class _Tp>
struct is_enum : public integral_constant<bool, __is_enum(_Tp)> {};

template<class _Tp>
inline constexpr bool is_enum_v = __is_enum(_Tp);

}  // namespace lc

#endif
