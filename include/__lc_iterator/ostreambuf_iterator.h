

#ifndef __LC_ITERATOR_OSTREAMBUF_ITERATOR_H
#define __LC_ITERATOR_OSTREAMBUF_ITERATOR_H

#include <streambuf>
#include <string>

#include "__lc_configs.h"
#include "__lc_iterator/iterator_traits.h"

__LC_NAMESPACE_BEGIN

template <typename _CharTp, typename _Trait = std::char_traits<_CharTp>>
class ostreambuf_iterator
#if __LC_CPP_STD_VER < 17
    : public iterator<output_iterator_tag, void, void, void, void>
#endif  // __LC_CPP_STD_VER < 17
{
public:

    typedef output_iterator_tag                          iterator_category;
    typedef void                                         value_type;
    typedef void                                         difference_type;
    typedef void                                         pointer;
    typedef void                                         reference;
    typedef _CharTp                                      char_type;
    typedef _Trait                                       traits_type;
    typedef std::basic_streambuf<char_type, traits_type> streambuf_type;
    typedef std::basic_ostream<char_type, traits_type>   ostream_type;

public:

    ostreambuf_iterator(streambuf_type *__sbuf) __LC_NOEXCEPT
        : __sbuf_(__sbuf) {}

    ostreambuf_iterator(ostream_type &__s) __LC_NOEXCEPT
        : __sbuf_(__s.rdbuf()) {}

    ~ostreambuf_iterator() = default;

    ostreambuf_iterator &operator=(_CharTp __c) {
        if (__sbuf_ &&
            traits_type::eq_int_type(__sbuf_->sputc(__c), traits_type::eof())) {
            __sbuf_ = nullptr;
        }
        return *this;
    }

    ostreambuf_iterator &operator*() {
        return *this;
    }

    ostreambuf_iterator &operator++() {
        return *this;
    }

    ostreambuf_iterator &operator++(int) {
        return *this;
    }

    // __sbuf_ == nullptr iff after operating = operator and push an EOF
    bool failed() const __LC_NOEXCEPT {
        return __sbuf_ == nullptr;
    }

private:

    streambuf_type *__sbuf_;
};

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_OSTREAMBUF_ITERATOR_H
