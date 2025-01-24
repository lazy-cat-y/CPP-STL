

#ifndef __LC_ITERATOR_FRONT_INSERT_ITERATOR_H
#define __LC_ITERATOR_FRONT_INSERT_ITERATOR_H

#include <__lc_configs.h>

#include <algorithm>
#include <memory>

#include "__lc_iterator/iterator.h"
#include "__lc_iterator/iterator_traits.h"

__LC_NAMESPACE_BEGIN

template <class _Container>
class front_insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void> {
public:
    typedef output_iterator_tag iterator_category;
    typedef void                value_type;
    typedef void                difference_type;
    typedef void                pointer;
    typedef void                reference;

public:

    __LC_EXPLICIT front_insert_iterator(_Container &__x) :
        __container(std::addressof(__x)) {}

    front_insert_iterator &operator=(
        const typename _Container::value_type &__value) {
        __container->push_front(__value);
    }

    front_insert_iterator &operator=(
        typename _Container::value_type &&__value) {
        __container->push_front(std::move(__value));
    }

    front_insert_iterator &operator*() {}

    front_insert_iterator &operator++() {}

    front_insert_iterator operator++(int) {}

protected:
    _Container *__container;
};

__LC_NAMESPACE_END

#endif
