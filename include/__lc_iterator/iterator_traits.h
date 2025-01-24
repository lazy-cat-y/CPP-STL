

#ifndef __LC_ITERATOR_ITERATOR_TRAITS_H
#define __LC_ITERATOR_ITERATOR_TRAITS_H

#include <__lc_configs.h>

#include <cstddef>
#include <type_traits>

__LC_NAMESPACE_BEGIN

// clang-format off
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

// clang-format on

template <class _Tp>
struct __has_iterator {
    template <class _Up>
    static std::false_type __test(...);

    template <class _Up>
    static std::true_type __test(
        std::void_t<typename _Up::iterator_category> * = nullptr,
        std::void_t<typename _Up::value_type> *        = nullptr,
        std::void_t<typename _Up::difference_type> *   = nullptr,
        std::void_t<typename _Up::pointer> *           = nullptr,
        std::void_t<typename _Up::reference> *         = nullptr);

    static __LC_CONSTEXPR bool value = decltype(__test<_Tp>(
        nullptr, nullptr, nullptr, nullptr, nullptr))::value;
};

template <class _Tp>
struct __has_iterator_category {
    template <class _Up>
    static std::false_type __test(...);

    template <class _Up>
    static std::true_type __test(
        std::void_t<typename _Up::iterator_category> *);

    static __LC_CONSTEXPR bool value = decltype(__test<_Tp>(nullptr))::value;
};

template <class _Iter, bool>
struct __iterator_traits;

template <class _Iter, bool>
struct __iterator_traits_impl {};

template <class _Iter>
struct __iterator_traits_impl<_Iter, true> {
    typedef typename _Iter::difference_type   difference_type;
    typedef typename _Iter::value_type        value_type;
    typedef typename _Iter::pointer           pointer;
    typedef typename _Iter::reference         reference;
    typedef typename _Iter::iterator_category iterator_category;
};

template <class _Iter>
struct __iterator_traits<_Iter, true>
    : __iterator_traits_impl<
          _Iter, std::is_convertible<typename _Iter::iterator_category,
                                     input_iterator_tag>::value ||
                     std::is_convertible<typename _Iter::iterator_category,
                                         output_iterator_tag>::value> {};

template <class _Iter>
struct iterator_traits
    : __iterator_traits<_Iter, __has_iterator<_Iter>::value> {
    using __primary_template = iterator_traits;
};

// For pointers
template <class _Tp>
struct iterator_traits<_Tp *> {
    typedef std::ptrdiff_t             difference_type;
    typedef std::remove_cv_t<_Tp>      value_type;
    typedef _Tp                       *pointer;
    typedef _Tp                       &reference;
    typedef random_access_iterator_tag iterator_category;
};

// iterator category
template <class _Tp, class _Up,
          bool = __has_iterator_category<iterator_traits<_Tp>>::value>
struct __has_iterator_category_convertible_to
    : std::is_convertible<typename iterator_traits<_Tp>::iterator_category,
                          _Up> {};

template <class _Tp, class _Up>
struct __has_iterator_category_convertible_to<_Tp, _Up, false>
    : std::false_type {};

template <class _Tp>
using __has_input_iterator_category =
    __has_iterator_category_convertible_to<_Tp, input_iterator_tag>;

template <class _Tp>
using __has_forward_iterator_category =
    __has_iterator_category_convertible_to<_Tp, forward_iterator_tag>;

template <class _Tp>
using __has_bidirectional_iterator_category =
    __has_iterator_category_convertible_to<_Tp, bidirectional_iterator_tag>;

template <class _Tp>
using __has_random_access_iterator_category =
    __has_iterator_category_convertible_to<_Tp, random_access_iterator_tag>;

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_ITERATOR_TRAITS_H
