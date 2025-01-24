

#ifndef __LC_ITERATOR_INSERTER_H
#define __LC_ITERATOR_INSERTER_H

#include "__lc_configs.h"
#include "__lc_iterator/insert_iterator.h"

__LC_NAMESPACE_BEGIN

template <typename _Container>
insert_iterator<_Container> inserter(_Container                   &__c,
                                     typename _Container::iterator __i) {
    return insert_iterator<_Container>(__c, __i);
}

__LC_NAMESPACE_END

#endif  // __LC_ITERATOR_INSERTER_H
