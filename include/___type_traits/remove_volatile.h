
#ifndef ___TYPE_TRAITS_REMOVE_VOLATILE_H
#define ___TYPE_TRAITS_REMOVE_VOLATILE_H

#include "configs.h"
namespace lc {

#if __has_builtin(__remove_volatile)
template <class _Tp>
struct remove_volatile {
    using type __STL_NODEBUG = __remove_volatile(_Tp);
};

template <class _Tp>
using __remove_volatile_t = __remove_volatile(_Tp);
#else

template <class _Tp>
struct remove_volatile {
    typedef _Tp type;
};

template <class _Tp>
struct remove_volatile<volatile _Tp> {
    typedef _Tp type;
};

template <class _Tp>
using __remove_volatile_t = typename remove_volatile<_Tp>::type;
#endif

template <class _Tp>
using remove_volatile_t = __remove_volatile_t<_Tp>;

}

#endif  // ___TYPE_TRAITS_REMOVE_VOLATILE_H
