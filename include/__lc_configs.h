

#ifndef __CONFIGS_CONFIG_H
#define __CONFIGS_CONFIG_H

#if defined(__cplusplus)

#  if !defined(__LC_CPP_STD_VER)

#    if __cplusplus <= 201103L
#      define __LC_CPP_STD_VER 11
#    elif __cplusplus <= 201402L
#      define __LC_CPP_STD_VER 14
#    elif __cplusplus <= 201703L
#      define __LC_CPP_STD_VER 17
#    elif __cplusplus <= 202002L
#      define __LC_CPP_STD_VER 20
#    elif __cplusplus <= 202302L
#      define __LC_CPP_STD_VER 23
#    else
#      define __LC_CPP_STD_VER 26
#    endif
#  endif  // __LC_CPP_STD_VER

#  if __LC_CPP_STD_VER >= 11
#    define __LC_ALIGNOF(_Tp)    alignof(_Tp)
#    define __LC_ALIGNAS_TYPE(x) alignas(x)
#    define __LC_ALIGNAS(x)      alignas(x)
#    define __LC_NORETURN        [[noreturn]]
#    define __LC_NOEXCEPT        noexcept
#    define __LC_NOEXCEPT_(x)    noexcept(x)
#    define __LC_CONSTEXPR       constexpr
#    define __LC_NODISCARD
#    define __LC_FALLTHROUGH
#    define __LC_MAYBE_UNUSED
#    define __LC_EXPLICIT
#    if __LC_CPP_STD_VER >= 17
#      undef __LC_NODISCARD
#      undef __LC_FALLTHROUGH
#      undef __LC_MAYBE_UNUSED
#      undef __LC_EXPLICIT
#      define __LC_FALLTHROUGH  [[fallthrough]]
#      define __LC_MAYBE_UNUSED [[maybe_unused]]
#      define __LC_NODISCARD    [[nodiscard]]
#      define __LC_EXPLICIT     explicit
#    endif  // __LC_CPP_STD_VER >= 17
#  endif    // __LC_CPP_STD_VER >= 11

#endif      // __cplusplus

#if !defined(__LC_NODEBUG)
#  define __LC_NODEBUG __attribute__((__nodebug__))
#endif

#if !defined(__LC_NAMESPACE_BEGIN)
#  define __LC_NAMESPACE_BEGIN namespace lc {
#  define __LC_NAMESPACE_END   }
#endif

#endif /* __CONFIGS_CONFIG_H */
