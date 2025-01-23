

#ifndef ___TYPE_TRAITS_INTEGRAL_CONSTANT_H
#define ___TYPE_TRAITS_INTEGRAL_CONSTANT_H

#include "configs.h"

namespace lc {

template <class _Tp, _Tp __v>
struct integral_constant {
    static const _Tp          value = __v;
    typedef _Tp               value_type;
    typedef integral_constant type;

    constexpr operator value_type() const noexcept {
        return value;
    }
};

template <class _Tp, _Tp __v>
const _Tp integral_constant<_Tp, __v>::value;

typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

template <bool __v>
using _bool_constant __STL_NODEBUG = integral_constant<bool, __v>;

template <bool __v>
using bool_constant = integral_constant<bool, __v>;

}  // namespace lc

#endif /* ___TYPE_TRAITS_INTEGRAL_CONSTANT_H */
