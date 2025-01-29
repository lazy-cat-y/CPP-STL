

#ifndef __LC_ITERATOR_ISTREAM_ITERATOR_H
#define __LC_ITERATOR_ISTREAM_ITERATOR_H

#include <cstddef>
#include <istream>
#include <memory>
#include <string>

#include "__lc_configs.h"
#include "__lc_iterator/iterator.h"
#include "__lc_iterator/iterator_traits.h"

__LC_NAMESPACE_BEGIN

template <class _Tp, class _CharTp = char,
          class _Trait    = std::char_traits<_CharTp>,
          class _Distance = std::ptrdiff_t>
class istream_iterator
#if __LC_CPP_STD_VER < 17
    : public iterator<input_iterator_tag, _Tp, _Distance, const _Tp *,
                      const _Tp &>
#endif  // __LC_CPP_STD_VER < 17
{
public:

    typedef input_iterator_tag                  iterator_category;
    typedef _Tp                                 value_type;
    typedef _Distance                           difference_type;
    typedef const _Tp                          *pointer;
    typedef const _Tp                          &reference;
    typedef _CharTp                             char_type;
    typedef _Trait                              traits_type;
    typedef std::basic_istream<_CharTp, _Trait> istream_type;

public:

    __LC_CONSTEXPR istream_iterator() : __in_stream_(nullptr), __value_() {}

    istream_iterator(istream_type &__in_stream) :
        __in_stream_(std::addressof(__in_stream)) {
        if (!(*__in_stream_ >> __value_)) {
            __in_stream_ = nullptr;
        }
    }

    istream_iterator(const istream_iterator &__other) = default;

    ~istream_iterator() = default;

    const _Tp &operator*() const {
        return __value_;
    }

    const _Tp *operator->() const {
        return std::addressof(operator*());
    }

    istream_iterator &operator++() {
        if (!(*__in_stream_ >> __value_)) {
            __in_stream_ = nullptr;
        }
        return *this;
    }

    istream_iterator operator++(int) {
        istream_iterator __tmp(*this);
        ++(*this);
        return __tmp;
    }

    template <class _Up, class _CharUp, class _TraitU, class _DistanceU>
    friend bool operator==(
        const istream_iterator<_Up, _CharUp, _TraitU, _DistanceU> &__lhs,
        const istream_iterator<_Up, _CharUp, _TraitU, _DistanceU> &__rhs);

    template <class _Up, class _CharUp, class _TraitU, class _DistanceU>
    friend bool operator!=(
        const istream_iterator<_Up, _CharUp, _TraitU, _DistanceU> &__lhs,
        const istream_iterator<_Up, _CharUp, _TraitU, _DistanceU> &__rhs);

private:
    istream_type *__in_stream_;
    _Tp           __value_;
};

template <class _Tp, class _CharTp, class _Trait, class _Distance>
inline bool operator==(
    const istream_iterator<_Tp, _CharTp, _Trait, _Distance> &__lhs,
    const istream_iterator<_Tp, _CharTp, _Trait, _Distance> &__rhs) {
    return __lhs.__in_stream_ == __rhs.__in_stream_;
}

template <class _Tp, class _CharTp, class _Trait, class _Distance>
inline bool operator!=(
    const istream_iterator<_Tp, _CharTp, _Trait, _Distance> &__lhs,
    const istream_iterator<_Tp, _CharTp, _Trait, _Distance> &__rhs) {
    return !(__lhs == __rhs);
}

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_ISTREAM_ITERATOR_H
