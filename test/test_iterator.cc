

#include <gtest/gtest.h>

#include <iterator>

#include "__lc_iterator.h"
#include "__lc_iterator/prev.h"

// test reverse_iterator
TEST(Iterator, reverse_iterator) {
    // iterate
    int                         arr[] = {1, 2, 3, 4, 5};
    lc::reverse_iterator<int *> rev_iter(arr + 5);
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
    lc::reverse_iterator<int *> rev_iter2(rev_iter);
    EXPECT_EQ(rev_iter, rev_iter2);
}

// test move_iterator
TEST(Iterator, move_iterator) {
    // iterate
    int                      arr[] = {1, 2, 3, 4, 5};
    lc::move_iterator<int *> move_iter(arr);
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
    lc::move_iterator<int *> move_iter2(move_iter);
    EXPECT_EQ(move_iter, move_iter2);
}

// test istreambuf_iterator
TEST(Iterator, istreambuf_iterator) {
    // iterate
    std::istringstream            in {"Hello, world"};
    lc::istreambuf_iterator<char> it {in}, end;
    EXPECT_EQ(*it, 'H');
    it++;
    EXPECT_EQ(*it, 'e');
    it++;
    EXPECT_EQ(*it, 'l');
    it++;
    EXPECT_EQ(*it, 'l');
    it++;
    EXPECT_EQ(*it, 'o');
    it++;
    EXPECT_EQ(*it, ',');
    it++;
    EXPECT_EQ(*it, ' ');
    it++;
    EXPECT_EQ(*it, 'w');
    it++;
    EXPECT_EQ(*it, 'o');
    it++;
    EXPECT_EQ(*it, 'r');
    it++;
    EXPECT_EQ(*it, 'l');
    it++;
    EXPECT_EQ(*it, 'd');
    it++;
    EXPECT_EQ(it, end);
}

// test ostreambuf_iterator
TEST(Iterator, ostreambuf_iterator) {
    // iterate
    std::ostringstream            out;
    lc::ostreambuf_iterator<char> it {out};
    *it = 'H';
    it++;
    *it = 'e';
    it++;
    *it = 'l';
    it++;
    *it = 'l';
    it++;
    *it = 'o';
    it++;
    *it = ',';
    it++;
    *it = ' ';
    it++;
    *it = 'w';
    it++;
    *it = 'o';
    it++;
    *it = 'r';
    it++;
    *it = 'l';
    it++;
    *it = 'd';
    it++;
    EXPECT_EQ(out.str(), "Hello, world");
}

// test istream_iterator
TEST(Iterator, istream_iterator) {
    // iterate
    std::istringstream        in {"1 2 3 4 5"};
    lc::istream_iterator<int> it {in}, end;
    EXPECT_EQ(*it, 1);
    it++;
    EXPECT_EQ(*it, 2);
    it++;
    EXPECT_EQ(*it, 3);
    it++;
    EXPECT_EQ(*it, 4);
    it++;
    EXPECT_EQ(*it, 5);
    it++;
    EXPECT_EQ(it, end);
}

// test ostream_iterator
TEST(Iterator, ostream_iterator) {
    // iterate
    std::ostringstream        out;
    lc::ostream_iterator<int> it {out, " "};
    *it = 1;
    it++;
    *it = 2;
    it++;
    *it = 3;
    it++;
    *it = 4;
    it++;
    *it = 5;
    it++;
    EXPECT_EQ(out.str(), "1 2 3 4 5 ");
}

// test advance
TEST(Iterator, advance) {
    // iterate
    int  arr[] = {1, 2, 3, 4, 5};
    auto it    = arr;
    lc::advance(it, 2);
    EXPECT_EQ(*it, 3);
    lc::advance(it, -2);
    EXPECT_EQ(*it, 1);
}

// test distance
TEST(Iterator, distance) {
    // iterate
    int  arr[] = {1, 2, 3, 4, 5};
    auto it1   = arr;
    auto it2   = arr + 3;
    EXPECT_EQ(lc::distance(it1, it2), 3);
    EXPECT_EQ(lc::distance(it2, it1), -3);
}

// test next
TEST(Iterator, next) {
    // iterate
    int  arr[] = {1, 2, 3, 4, 5};
    auto it    = arr;
    auto it2   = lc::next(it, 2);
    EXPECT_EQ(*it2, 3);
    it2 = lc::next(it2, -2);
    EXPECT_EQ(*it2, 1);
}

// test prev
TEST(Iterator, prev) {
    // iterate
    int  arr[] = {1, 2, 3, 4, 5};
    auto it    = arr + 3;
    auto it2   = lc::prev(it, 2);
    EXPECT_EQ(*it2, 2);
}

// test begin and end in all 3 cases: _C &__c, const _C &__c, _Tp (&__array)[_N]
TEST(Iterator, begin_end) {
    // iterate
    int arr[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(*lc::begin(arr), 1);
    EXPECT_EQ(*lc::prev(lc::end(arr)), 5);
    std::vector<int> vec {1, 2, 3, 4, 5};
    EXPECT_EQ(*lc::begin(vec), 1);
    EXPECT_EQ(*lc::prev(lc::end(vec)), 5);
    const std::vector<int> cvec {1, 2, 3, 4, 5};
    EXPECT_EQ(*lc::begin(cvec), 1);
    EXPECT_EQ(*lc::prev(lc::end(cvec)), 5);
}

// test cbegin and cend cbegin(const _C &__C)
TEST(Iterator, cbegin_cend) {
    // iterate
    int arr[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(*lc::cbegin(arr), 1);
    EXPECT_EQ(*lc::prev(lc::cend(arr)), 5);
    std::vector<int> vec {1, 2, 3, 4, 5};
}

// test rbegin and rend
TEST(Iterator, rbegin_rend) {
    // iterate
    int arr[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(*lc::rbegin(arr), 5);
    std::vector<int> vec {1, 2, 3, 4, 5};
    EXPECT_EQ(*lc::rbegin(vec), 5);
    const std::vector<int> cvec {1, 2, 3, 4, 5};
    EXPECT_EQ(*lc::rbegin(cvec), 5);
}

// test crbegin and crend
TEST(Iterator, crbegin_crend) {
    // iterate
    int arr[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(*lc::crbegin(arr), 5);
}

// test size
TEST(Iterator, size) {
    // iterate
    int arr[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(lc::size(arr), 5);
    std::vector<int> vec {1, 2, 3, 4, 5};
    EXPECT_EQ(lc::size(vec), 5);
    const std::vector<int> cvec {1, 2, 3, 4, 5};
    EXPECT_EQ(lc::size(cvec), 5);
}

// test empty
TEST(Iterator, empty) {
    // iterate
    int arr[] = {1, 2, 3, 4, 5};
    EXPECT_FALSE(lc::empty(arr));
    std::vector<int> vec {1, 2, 3, 4, 5};
    EXPECT_FALSE(lc::empty(vec));
    const std::vector<int> cvec {1, 2, 3, 4, 5};
    EXPECT_FALSE(lc::empty(cvec));
}

// test data
TEST(Iterator, data) {
    // iterate
    int arr[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(*lc::data(arr), 1);
    std::vector<int> vec {1, 2, 3, 4, 5};
    EXPECT_EQ(*lc::data(vec), 1);
    const std::vector<int> cvec {1, 2, 3, 4, 5};
    EXPECT_EQ(*lc::data(cvec), 1);
}
