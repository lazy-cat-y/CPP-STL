

#ifndef __TYPE_TRAITS_IS_SAME_H
#define __TYPE_TRAITS_IS_SAME_H

#include "___type_traits/integral_constant.h"
namespace lc {

template<class _Tp, class _Up>
struct is_same : false_type {};

template<class _Tp>
struct is_same<_Tp, _Tp> : true_type {};

template<class _Tp, class _Up>
inline constexpr bool is_same_v = is_same<_Tp, _Up>::value;

}  // namespace lc

#endif  // __TYPE_TRAITS_IS_SAME_H
