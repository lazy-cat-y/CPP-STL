

#ifndef __LC_ITERATOR_ISTREAMBUF_ITERATOR_H
#define __LC_ITERATOR_ISTREAMBUF_ITERATOR_H

#include <istream>
#include <streambuf>
#include <string>

#include "__lc_configs.h"
#include "__lc_iterator/front_insert_iterator.h"
#include "__lc_iterator/iterator_traits.h"

__LC_NAMESPACE_BEGIN

template <typename _CharTp, typename _Trait = std::char_traits<_CharTp>>
class istreambuf_iterator
#if __LC_CPP_STD_VER < 17
    : public iterator<input_iterator_tag, _CharTp, std::ptrdiff_t,
                      const _CharTp *, const _CharTp &>
#endif  // __LC_CPP_STD_VER < 17
{
public:

    typedef input_iterator_tag                    iterator_category;
    typedef _CharTp                               value_type;
    typedef typename _Trait::off_type             difference_type;
    typedef _CharTp                              *pointer;
    typedef _CharTp                              &reference;
    typedef _CharTp                               char_type;
    typedef _Trait                                traits_type;
    typedef typename _Trait::int_type             int_type;
    typedef std::basic_streambuf<_CharTp, _Trait> streambuf_type;
    typedef std::basic_istream<_CharTp, _Trait>   istream_type;
private:
    class __proxy;

public:

    __LC_CONSTEXPR istreambuf_iterator() __LC_NOEXCEPT : __sbuf_(nullptr) {}

    istreambuf_iterator(istream_type &__is) __LC_NOEXCEPT
        : __sbuf_(__is.rdbuf()) {}

    istreambuf_iterator(streambuf_type *__sbuf) __LC_NOEXCEPT
        : __sbuf_(__sbuf) {}

    istreambuf_iterator(const __proxy &p) __LC_NOEXCEPT : __sbuf_(p.__sbuf_) {}

    istreambuf_iterator(const istreambuf_iterator &__other)
        __LC_NOEXCEPT = default;

    ~istreambuf_iterator() = default;

    char_type operator*() const {
        return static_cast<char_type>(__sbuf_->sgetc());
    }

    istreambuf_iterator operator++() {
        __sbuf_->sbumpc();
        return *this;
    }

    __proxy operator++(int) {
        return __proxy(__sbuf_->sbumpc(), __sbuf_);
    }

    // Checks whether both *this and it are valid, or both are invalid,
    // regardless of the stream buffer objects they use.
    bool equal(const istreambuf_iterator &__other) const {
        return __check_eof() == __other.__check_eof();
    }

    template <typename _CharUp, typename _TraitU>
    friend bool operator==(const istreambuf_iterator &__lhs,
                           const istreambuf_iterator &__rhs);

    template <typename _CharUp, typename _TraitU>
    friend bool operator!=(const istreambuf_iterator &__lhs,
                           const istreambuf_iterator &__rhs);

private:

    mutable streambuf_type *__sbuf_;

    class __proxy {
        char_type       __char_;
        streambuf_type *__sbuf_;

        __LC_EXPLICIT __proxy(char_type __c, streambuf_type *__s) :
            __char_(__c),
            __sbuf_(__s) {}

        friend class istreambuf_iterator;

    public:

        __LC_CONSTEXPR char_type operator*() const {
            return __char_;
        }
    };

    bool __check_eof() const {
        if (__sbuf_ &&
            traits_type::eq_int_type(__sbuf_->sgetc(), traits_type::eof())) {
            __sbuf_ = nullptr;
        }
        return __sbuf_ == nullptr;
    }
};

template <typename _CharTp, typename _Trait>
bool operator==(const istreambuf_iterator<_CharTp, _Trait> &__lhs,
                const istreambuf_iterator<_CharTp, _Trait> &__rhs) {
    return __lhs.equal(__rhs);
}

template <typename _CharTp, typename _Trait>
bool operator!=(const istreambuf_iterator<_CharTp, _Trait> &__lhs,
                const istreambuf_iterator<_CharTp, _Trait> &__rhs) {
    return !(__lhs == __rhs);
}

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_ISTREAMBUF_ITERATOR_H
