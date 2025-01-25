

#ifndef __LC_ITERATOR_OSTREAM_ITERATOR_H
#define __LC_ITERATOR_OSTREAM_ITERATOR_H

#include <string>

#include "__lc_configs.h"
#include "__lc_iterator/iterator.h"
#include "__lc_iterator/iterator_traits.h"

__LC_NAMESPACE_BEGIN

template <typename _Tp, typename _CharTp = char,
          typename _Trait = std::char_traits<_CharTp>>
#if __LC_CPP_STD_VER < 17
class ostream_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
#endif  // __LC_CPP_STD_VER < 17
      class ostream_iterator {
public:

    typedef output_iterator_tag                 iterator_category;
    typedef void                                value_type;
    typedef void                                difference_type;
    typedef void                                pointer;
    typedef void                                reference;
    typedef _CharTp                             char_type;
    typedef _Trait                              traits_type;
    typedef std::basic_ostream<_CharTp, _Trait> ostream_type;

public:

    ostream_iterator(ostream_type &__out_stream_) :
        __out_stream_(std::addressof(__out_stream_)),
        __delim_(nullptr) {}

    ostream_iterator(ostream_type &__out_stream_, const _CharTp *__delim_) :
        __out_stream_(std::addressof(__out_stream_)),
        __delim_(__delim_) {}

    ~ostream_iterator() = default;

    ostream_iterator &operator=(const ostream_iterator &__other) {
        return *this;
    }

    ostream_iterator &operator=(const _Tp &__value) {
        *__out_stream_ << __value;
        if (__delim_) {
            *__out_stream_ << __delim_;
        }
        return *this;
    }

    ostream_iterator &operator*() {
        return *this;
    }

    ostream_iterator &operator++() {
        return *this;
    }

    ostream_iterator &operator++(int) {
        return *this;
    }

private:
    ostream_type  *__out_stream_;
    const _CharTp *__delim_;
};

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_OSTREAM_ITERATOR_H
