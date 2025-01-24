

#ifndef __LC_ITERATOR_BACK_INSERT_ITERATOR_H
#define __LC_ITERATOR_BACK_INSERT_ITERATOR_H

#include <memory>

#include "__lc_configs.h"
#include "__lc_iterator/iterator.h"
#include "__lc_iterator/iterator_traits.h"

__LC_NAMESPACE_BEGIN

template <typename _Container>
class back_insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void> {
public:

    typedef output_iterator_tag iterator_category;
    typedef void                value_type;
    typedef void                difference_type;
    typedef void                pointer;
    typedef void                reference;
    typedef _Container          container_type;

public:

    __LC_EXPLICIT back_insert_iterator(_Container &__c) :
        container(std::addressof(__c)) {}

    back_insert_iterator &operator=(
        const typename _Container::value_type &__value) {
        container->push_back(__value);
        return *this;
    }

    back_insert_iterator &operator=(typename _Container::value_type &&__value) {
        container->push_back(std::move(__value));
        return *this;
    }

    back_insert_iterator &operator*() {}

    back_insert_iterator &operator++() {}

    back_insert_iterator operator++(int) {}

protected:
    container_type *container;
};

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_BACK_INSERT_ITERATOR_H
