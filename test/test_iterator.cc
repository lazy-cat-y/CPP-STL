

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

// test move_iterator
TEST(Iterator, move_iterator) {
    // iterate 
    int arr[] = {1, 2, 3, 4, 5};
    lc::move_iterator<int*> move_iter(arr);
    // std::move_iterator<int*> move_iter(arr);
    EXPECT_EQ(move_iter[2], 3);
    EXPECT_EQ(*move_iter, 1);
    move_iter++;
    EXPECT_EQ(*move_iter, 2);
    move_iter++;
    EXPECT_EQ(*move_iter, 3);
    move_iter--;
    EXPECT_EQ(*move_iter, 2);
    move_iter += 2;
    EXPECT_EQ(*move_iter, 4);
    move_iter -= 2;
    EXPECT_EQ(*move_iter, 2);
    lc::move_iterator<int*> move_iter2(move_iter);
    EXPECT_EQ(move_iter, move_iter2);
}
