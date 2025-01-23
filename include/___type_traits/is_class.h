

#ifndef ___TYPE_TRAITS_IS_CLASS_H
#define ___TYPE_TRAITS_IS_CLASS_H

#include "___type_traits/integral_constant.h"

namespace lc {

template<class _Tp>
struct is_class : public integral_constant<bool, __is_class(_Tp)> {};

template<class _Tp>
inline constexpr bool is_class_v = __is_class(_Tp);

}  // namespace lc

#endif // ___TYPE_TRAITS_IS_CLASS_H
