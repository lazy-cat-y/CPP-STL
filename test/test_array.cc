

#include <__lc_containers.h>
#include <gtest/gtest.h>

#include "__lc_containers/array.h"
#include "__lc_iterator/prev.h"

// constructor
TEST(ArrayTest, DefaultConstructor) {
    lc::array<int, 5> arr {1, 2, 3, 4, 5};
    EXPECT_EQ(arr.size(), 5);
}

// at and []
TEST(ArrayTest, FillConstructor) {
    lc::array<int, 5> arr {1, 2, 3, 4, 5};
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 5);
    EXPECT_EQ(arr.at(3), 4);
    // out of range
    EXPECT_THROW(arr.at(5), std::out_of_range);
}

// front and back
TEST(ArrayTest, FrontAndBack) {
    lc::array<int, 5> arr {1, 2, 3, 4, 5};
    EXPECT_EQ(arr.front(), 1);
    EXPECT_EQ(arr.back(), 5);
}

// data
TEST(ArrayTest, Data) {
    lc::array<int, 5> arr {1, 2, 3, 4, 5};

    int *data = arr.data();

    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[1], 2);
    EXPECT_EQ(data[2], 3);
    EXPECT_EQ(data[3], 4);
    EXPECT_EQ(data[4], 5);
}

// begin and end
TEST(ArrayTest, BeginAndEnd) {
    lc::array<int, 5> arr {1, 2, 3, 4, 5};

    auto begin = arr.begin();
    auto end   = lc::prev(arr.end());

    EXPECT_EQ(*begin, 1);
    EXPECT_EQ(*end, 5);
}

// cbegin and cend
TEST(ArrayTest, CBeginAndCEnd) {
    lc::array<int, 5> arr {1, 2, 3, 4, 5};
    auto              begin = arr.cbegin();
    auto              end   = lc::prev(arr.cend());
    EXPECT_EQ(*begin, 1);
    EXPECT_EQ(*end, 5);
}

// rbegin and rend
TEST(ArrayTest, RBeginAndREnd) {
    lc::array<int, 5> arr {1, 2, 3, 4, 5};

    auto rbegin = arr.rbegin();
    auto rend   = arr.rend();

    EXPECT_EQ(*rbegin, 5);
    EXPECT_EQ(*rend, 1);
}

// crbegin and crend
TEST(ArrayTest, CRBeginAndCREnd) {
    lc::array<int, 5> arr {1, 2, 3, 4, 5};

    auto rbegin = arr.crbegin();
    auto rend   = arr.crend();

    EXPECT_EQ(*rbegin, 5);
    EXPECT_EQ(*rend, 1);
}

// empty, size, max_size
TEST(ArrayTest, EmptySizeMaxSize) {
    lc::array<int, 5> arr {1, 2, 3, 4, 5};
    EXPECT_FALSE(arr.empty());
    EXPECT_EQ(arr.size(), 5);
    EXPECT_EQ(arr.max_size(), 5);
}

// fill
TEST(ArrayTest, Fill) {
    lc::array<int, 5> arr {1, 2, 3, 4, 5};
    arr.fill(0);
    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[1], 0);
    EXPECT_EQ(arr[2], 0);
    EXPECT_EQ(arr[3], 0);
    EXPECT_EQ(arr[4], 0);
}

// swap
TEST(ArrayTest, Swap) {
    lc::array<int, 5> arr1 {1, 2, 3, 4, 5};
    lc::array<int, 5> arr2 {5, 4, 3, 2, 1};
    arr1.swap(arr2);
    EXPECT_EQ(arr1[0], 5);
    EXPECT_EQ(arr1[1], 4);
    EXPECT_EQ(arr1[2], 3);
    EXPECT_EQ(arr1[3], 2);
    EXPECT_EQ(arr1[4], 1);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);
    EXPECT_EQ(arr2[3], 4);
    EXPECT_EQ(arr2[4], 5);
}

// operator==
TEST(ArrayTest, OperatorEqual) {
    lc::array<int, 5> arr1 {1, 2, 3, 4, 5};
    lc::array<int, 5> arr2 {1, 2, 3, 4, 5};
    EXPECT_TRUE(arr1 == arr2);
}

// operator!=
TEST(ArrayTest, OperatorNotEqual) {
    lc::array<int, 5> arr1 {1, 2, 3, 4, 5};
    lc::array<int, 5> arr2 {5, 4, 3, 2, 1};
    EXPECT_TRUE(arr1 != arr2);
}

// operator<
TEST(ArrayTest, OperatorLess) {
    lc::array<int, 5> arr1 {1, 2, 3, 4, 5};
    lc::array<int, 5> arr2 {5, 4, 3, 2, 1};
    EXPECT_TRUE(arr1 < arr2);
}

// operator>
TEST(ArrayTest, OperatorGreater) {
    lc::array<int, 5> arr1 {1, 2, 3, 4, 5};
    lc::array<int, 5> arr2 {5, 4, 3, 2, 1};
    EXPECT_TRUE(arr2 > arr1);
}

// operator<=
TEST(ArrayTest, OperatorLessEqual) {
    lc::array<int, 5> arr1 {1, 2, 3, 4, 5};
    lc::array<int, 5> arr2 {5, 4, 3, 2, 1};
    EXPECT_TRUE(arr1 <= arr2);
}

// operator>=
TEST(ArrayTest, OperatorGreaterEqual) {
    lc::array<int, 5> arr1 {1, 2, 3, 4, 5};
    lc::array<int, 5> arr2 {5, 4, 3, 2, 1};
    EXPECT_TRUE(arr2 >= arr1);
}

// get
TEST(ArrayTest, Get) {
    lc::array<int, 5> arr {1, 2, 3, 4, 5};
    EXPECT_EQ(lc::get<2>(arr), 3);
}
