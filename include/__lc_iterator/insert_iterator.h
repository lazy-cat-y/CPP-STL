

#ifndef __LC_ITERATOR_INSERT_ITERATOR_H
#define __LC_ITERATOR_INSERT_ITERATOR_H

#include <algorithm>
#include <memory>

#include "__lc_configs.h"
#include "__lc_iterator/iterator.h"
#include "__lc_iterator/iterator_traits.h"

__LC_NAMESPACE_BEGIN

template <typename _Container>
class insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void> {
public:

    typedef output_iterator_tag iterator_category;
    typedef void                value_type;
    typedef void                difference_type;
    typedef void                pointer;
    typedef void                reference;
    typedef _Container          container_type;

public:

    insert_iterator(_Container &__c, typename _Container::iterator __i) :
        __container(std::addressof(__c)),
        __iter(__i) {}

    insert_iterator &operator=(const typename _Container::value_type &__value) {
        __iter = __container->insert(__iter, __value);
        ++__iter;
        return *this;
    }

    insert_iterator &operator=(typename _Container::value_type &&__value) {
        __iter = __container->insert(__iter, std::move(__value));
        ++__iter;
        return *this;
    }

    insert_iterator &operator*() {
        return *this;
    }

    insert_iterator &operator++() {
        return *this;
    }

    insert_iterator operator++(int) {
        return *this;
    }

protected:
    _Container                   *__container;
    typename _Container::iterator __iter;
};

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_INSERT_ITERATOR_H
