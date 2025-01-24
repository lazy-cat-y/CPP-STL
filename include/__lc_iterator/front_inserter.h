

#ifndef __LC_ITERATOR_FRONT_INSERTER_H
#define __LC_ITERATOR_FRONT_INSERTER_H

#include <__lc_configs.h>

#include "__lc_iterator/front_insert_iterator.h"

__LC_NAMESPACE_BEGIN

template <class _Container>
front_insert_iterator<_Container> front_inserter(_Container &__c) {
    return front_insert_iterator<_Container>(__c);
}

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_FRONT_INSERTER_H
