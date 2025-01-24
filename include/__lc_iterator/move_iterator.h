

#ifndef __LC_ITERATOR_MOVE_ITERATOR_H
#define __LC_ITERATOR_MOVE_ITERATOR_H

#include <algorithm>
#include <type_traits>

#include "__lc_configs.h"
#include "__lc_iterator/iterator_traits.h"

__LC_NAMESPACE_BEGIN

template <class _Iter>
class move_iterator {

public:
    typedef _Iter iterator_type;

    // undefined if std::iterator_traits<Iter>::iterator_category is invalid or
    // does not denote a type std::random_access_iterator_tag if
    // std::iterator_traits<Iter>::iterator_category models
    // std::derived_from<std::random_access_iterator_tag>
    // std::iterator_traits<Iter>::iterator_category otherwise
    typedef typename std::conditional<
        __has_random_access_iterator_category<_Iter>::value,
        random_access_iterator_tag,
        typename iterator_traits<_Iter>::iterator_category>::value
        iterator_concept;

    typedef typename iterator_traits<_Iter>::value_type      value_type;
    typedef typename iterator_traits<_Iter>::difference_type difference_type;
    typedef iterator_type                                    pointer;

    // the rvalue reference version of std::iterator_traits<Iter>::reference if
    // std::iterator_traits<Iter>::reference is a reference type
    // std::iterator_traits<Iter>::reference otherwise
    typedef typename iterator_traits<_Iter>::reference __tmp_reference;
    typedef
        typename std::conditional<std::is_reference<__tmp_reference>::value,
                                  std::remove_reference_t<__tmp_reference> &&,
                                  __tmp_reference>::value reference;

public:

    // Constructors
    __LC_CONSTEXPR move_iterator() : __current() {}

    __LC_EXPLICIT __LC_CONSTEXPR move_iterator(iterator_type __i) :
        __current(std::move(__i)) {}

    template <class _Up>
    __LC_CONSTEXPR move_iterator(const move_iterator<_Up> &__other) :
        __current(__other.base()) {}

    // This overload participates in overload resolution only if
    // std::is_same_v<U, Iter> is false and both std::convertible_to<const U&,
    // Iter> and std::assignable_from<Iter&, const U&> are modeled.
    template <class _Up, class = std::enable_if_t<
                             !std::is_same<_Up, _Iter>::value &&
                             std::is_convertible<const _Up &, _Iter>::value &&
                             std::is_assignable<_Iter &, const _Up &>::value>>
    __LC_CONSTEXPR move_iterator &operator=(const move_iterator<_Up> &__other) {
        __current = __other.base();
        return *this;
    }

    __LC_CONSTEXPR iterator_type base() const {
        return __current;
    }

    __LC_CONSTEXPR reference operator*() const {
        return static_cast<reference>(*__current);
    }

    __LC_CONSTEXPR pointer operator->() const {
        return __current;
    }

    __LC_CONSTEXPR reference operator[](difference_type __n) const {
        return static_cast<reference>(__current[__n]);
    }

    // move_iterator& operator++();
    // move_iterator& operator--();
    // move_iterator operator++( int );
    // move_iterator operator--( int );
    // move_iterator operator+( difference_type n ) const;
    // move_iterator operator-( difference_type n ) const;
    // move_iterator& operator+=( difference_type n );
    // move_iterator& operator-=( difference_type n );

private:
    iterator_type __current;
};

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_MOVE_ITERATOR_H
