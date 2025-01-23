
#ifndef ___TYPE_TRAITS_IS_ARRAY_H
#define ___TYPE_TRAITS_IS_ARRAY_H

#include <cstddef>

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

template <typename _Tp>
struct is_array : public false_type {};

template <typename _Tp>
struct is_array<_Tp[]> : public true_type {};

template <typename _Tp, std::size_t _Np>
struct is_array<_Tp[_Np]> : public true_type {};

#if __STL_CPP_VERSION >= 17
template <typename _Tp>
inline constexpr bool is_array_v = is_array<_Tp>::value;
#endif

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_ARRAY_H
