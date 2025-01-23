

#ifndef ___TYPE_TRAITS_IS_REFERENCE_H
#define ___TYPE_TRAITS_IS_REFERENCE_H

#include "___type_traits/integral_constant.h"
#include "configs.h"

namespace lc {

#if __has_builtin(__is_lvalue_reference) &&                               \
    __has_builtin(__is_rvalue_reference) && __has_builtin(__is_reference)

template <class _Tp>
struct is_lvalue_reference : bool_constant<__is_lvalue_reference(_Tp)> {};

template <class _Tp>
struct is_rvalue_reference : bool_constant<__is_rvalue_reference(_Tp)> {};

template <class _Tp>
struct is_reference : bool_constant<__is_reference(_Tp)> {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_lvalue_reference_v = __is_lvalue_reference(_Tp);
template <class _Tp>
inline constexpr bool is_rvalue_reference_v = __is_rvalue_reference(_Tp);
template <class _Tp>
inline constexpr bool is_reference_v = __is_reference(_Tp);
#  endif

#else     // __has_builtin(__is_lvalue_reference) && etc...

template <class _Tp>
struct is_lvalue_reference : public false_type {};
template <class _Tp>
struct is_lvalue_reference<_Tp &> : public true_type {};

template <class _Tp>
struct is_rvalue_reference : public false_type {};
template <class _Tp>
struct is_rvalue_reference<_Tp &&> : public true_type {};

template <class _Tp>
struct is_reference : public false_type {};
template <class _Tp>
struct is_reference<_Tp &> : public true_type {};
template <class _Tp>
struct is_reference<_Tp &&> : public true_type {};

#  if __STL_CPP_VERSION >= 17
template <class _Tp>
inline constexpr bool is_lvalue_reference_v = is_lvalue_reference<_Tp>::value;
template <class _Tp>
inline constexpr bool is_rvalue_reference_v = is_rvalue_reference<_Tp>::value;
template <class _Tp>
inline constexpr bool is_reference_v = is_reference<_Tp>::value;
#  endif  // __STL_CPP_VERSION >= 17

#endif    // __has_builtin(__is_lvalue_reference) && etc...

}  // namespace lc

#endif  // ___TYPE_TRAITS_IS_REFERENCE_H
