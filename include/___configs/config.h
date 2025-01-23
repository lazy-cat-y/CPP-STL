

#ifndef __CONFIGS_CONFIG_H
#define __CONFIGS_CONFIG_H

#if defined(_PTHREADS) || defined(_POSIX_THREADS) || defined(_REENTRANT)
#  define __STL_MULTITHREADED
#elif defined(_WIN32) || defined(__WIN32__)
#  define __STL_MULTITHREADED
#endif

#if !defined(__STL_THROW_BAD_ALLOC)
#  include <new>
#  define __STL_THROW_BAD_ALLOC throw std::bad_alloc
#endif

#if !defined(__STL_NOEXCEPT)
#  if __cplusplus >= 201103L
#    define __STL_NOEXCEPT noexcept
#  else
#    define __STL_NOEXCEPT throw()
#  endif
#endif

#if !defined(__STL_NODEBUG)
#define __STL_NODEBUG __attribute__((__nodebug__))
#endif

#endif /* __CONFIGS_CONFIG_H */
