

#include <gtest/gtest.h>
#include <iterator>

#include "__lc_iterator.h"

// test reverse_iterator
TEST(Iterator, reverse_iterator) {
    // iterate 
    int arr[] = {1, 2, 3, 4, 5};
    lc::reverse_iterator<int*> rev_iter(arr + 5);
    EXPECT_EQ(rev_iter[2], 3);
    EXPECT_EQ(*rev_iter, 5);
    rev_iter++;
    EXPECT_EQ(*rev_iter, 4);
    rev_iter++;
    EXPECT_EQ(*rev_iter, 3);
    rev_iter--;
    EXPECT_EQ(*rev_iter, 4);
    rev_iter += 2;
    EXPECT_EQ(*rev_iter, 2);
    rev_iter -= 2;
    EXPECT_EQ(*rev_iter, 4);
    lc::reverse_iterator<int*> rev_iter2(rev_iter);
    EXPECT_EQ(rev_iter, rev_iter2);
}
