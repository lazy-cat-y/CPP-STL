

#ifndef __LC_ITERATOR_BACK_INSERTER_H
#define __LC_ITERATOR_BACK_INSERTER_H

#include "__lc_configs.h"
#include "__lc_iterator/back_insert_iterator.h"

__LC_NAMESPACE_BEGIN

template <typename _Container>
back_insert_iterator<_Container> back_inserter(_Container &__c) {
    return back_insert_iterator<_Container>(__c);
}

__LC_NAMESPACE_END

#endif
