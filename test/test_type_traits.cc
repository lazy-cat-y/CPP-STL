#include <gtest/gtest.h>

#include "type_traits.h"

// is same
TEST(TypeTraits, is_same) {
    static_assert(lc::is_same<int, int>::value, "int is same as int");
    static_assert(lc::is_same<const int, const int>::value,
                  "const int is same as const int");
    static_assert(lc::is_same<volatile int, volatile int>::value,
                  "volatile int is same as volatile int");
    static_assert(lc::is_same<const volatile int, const volatile int>::value,
                  "const volatile int is same as const volatile int");

    static_assert(!lc::is_same<int, const int>::value,
                  "int is not same as const int");
    static_assert(!lc::is_same<int, volatile int>::value,
                  "int is not same as volatile int");
    static_assert(!lc::is_same<int, const volatile int>::value,
                  "int is not same as const volatile int");
    static_assert(!lc::is_same<const int, volatile int>::value,
                  "const int is not same as volatile int");
    static_assert(!lc::is_same<const int, const volatile int>::value,
                  "const int is not same as const volatile int");
    static_assert(!lc::is_same<volatile int, const volatile int>::value,
                  "volatile int is not same as const volatile int");
}

// remove cv, remove const and remove volatile
TEST(TypeTraits, remove) {
    static_assert(
        lc::is_same<lc::remove_cv<int>::type, int>::value,
        "remove_cv<int> is same as int");
    static_assert(
        lc::is_same<lc::remove_cv<const int>::type, int>::value,
        "remove_cv<const int> is same as int");
    static_assert(
        lc::is_same<lc::remove_cv<volatile int>::type, int>::value,
        "remove_cv<volatile int> is same as int");
    static_assert(
        lc::is_same<lc::remove_cv<const volatile int>::type, int>::value,
        "remove_cv<const volatile int> is same as int");

    static_assert(
        lc::is_same<lc::remove_const<int>::type, int>::value,
        "remove_const<int> is same as int");
    static_assert(
        lc::is_same<lc::remove_const<const int>::type, int>::value,
        "remove_const<const int> is same as int");
    static_assert(
        lc::is_same<lc::remove_const<volatile int>::type, volatile int>::value,
        "remove_const<volatile int> is same as volatile int");
    static_assert(
        lc::is_same<lc::remove_const<const volatile int>::type,
                    volatile int>::value,
        "remove_const<const volatile int> is same as volatile int");

    static_assert(
        lc::is_same<lc::remove_volatile<int>::type, int>::value,
        "remove_volatile<int> is same as int");
    static_assert(
        lc::is_same<lc::remove_volatile<const int>::type, const int>::value,
        "remove_volatile<const int> is same as const int");
    static_assert(
        lc::is_same<lc::remove_volatile<volatile int>::type, int>::value,
        "remove_volatile<volatile int> is same as int");
    static_assert(
        lc::is_same<lc::remove_volatile<const volatile int>::type,
                    const int>::value,
        "remove_volatile<const volatile int> is same as const int");
}

// is void
TEST(TypeTraits, is_void) {
    static_assert(lc::is_void<void>::value, "void is void");
    static_assert(lc::is_void<const void>::value, "const void is void");
    static_assert(lc::is_void<volatile void>::value, "volatile void is void");
    static_assert(lc::is_void<const volatile void>::value,
                  "const volatile void is void");

    static_assert(!lc::is_void<int>::value, "int is not void");
    static_assert(!lc::is_void<const int>::value, "const int is not void");
    static_assert(!lc::is_void<volatile int>::value,
                  "volatile int is not void");
    static_assert(!lc::is_void<const volatile int>::value,
                  "const volatile int is not void");
}

// is null pointer
TEST(TypeTraits, is_null_pointer) {
    static_assert(lc::is_null_pointer<std::nullptr_t>::value,
                  "std::nullptr_t is null pointer");

    static_assert(!lc::is_null_pointer<int>::value, "int is not null pointer");
    static_assert(!lc::is_null_pointer<const int>::value,
                  "const int is not null pointer");
    static_assert(!lc::is_null_pointer<volatile int>::value,
                  "volatile int is not null pointer");
    static_assert(!lc::is_null_pointer<const volatile int>::value,
                  "const volatile int is not null pointer");
}

// is array
TEST(TypeTraits, is_array) {
    static_assert(lc::is_array<int[]>::value, "int[] is array");
    static_assert(lc::is_array<int[5]>::value, "int[5] is array");

    static_assert(!lc::is_array<int>::value, "int is not array");
    static_assert(!lc::is_array<const int>::value, "const int is not array");
    static_assert(!lc::is_array<volatile int>::value, "volatile int is not array");
    static_assert(!lc::is_array<const volatile int>::value, "const volatile int is not array");
}

// is enum
TEST(TypeTraits, is_enum) {
    static_assert(!lc::is_enum<int>::value, "int is enum");
    static_assert(!lc::is_enum<const int>::value, "const int is enum");
    static_assert(!lc::is_enum<volatile int>::value, "volatile int is enum");
    static_assert(!lc::is_enum<const volatile int>::value, "const volatile int is enum");

    static_assert(!lc::is_enum<int[]>::value, "int[] is not enum");
    static_assert(!lc::is_enum<int[5]>::value, "int[5] is not enum");

    enum E { e1, e2 };
    static_assert(lc::is_enum<E>::value, "E is enum");
}

// is union
TEST(TypeTraits, is_union) {
    static_assert(!lc::is_union<int>::value, "int is union");
    static_assert(!lc::is_union<const int>::value, "const int is union");
    static_assert(!lc::is_union<volatile int>::value, "volatile int is union");
    static_assert(!lc::is_union<const volatile int>::value, "const volatile int is union");

    static_assert(!lc::is_union<int[]>::value, "int[] is not union");
    static_assert(!lc::is_union<int[5]>::value, "int[5] is not union");

    union U {
        int i;
        double d;
    };
    static_assert(lc::is_union<U>::value, "U is union");
}

// is class
TEST(TypeTraits, is_class) {
    static_assert(!lc::is_class<int>::value, "int is class");
    static_assert(!lc::is_class<const int>::value, "const int is class");
    static_assert(!lc::is_class<volatile int>::value, "volatile int is class");
    static_assert(!lc::is_class<const volatile int>::value, "const volatile int is class");

    static_assert(!lc::is_class<int[]>::value, "int[] is not class");
    static_assert(!lc::is_class<int[5]>::value, "int[5] is not class");

    class C {};
    static_assert(lc::is_class<C>::value, "C is class");
}

// is function
TEST(TypeTraits, is_function) {
    static_assert(!lc::is_function<int>::value, "int is function");
    static_assert(!lc::is_function<const int>::value, "const int is function");
    static_assert(!lc::is_function<volatile int>::value, "volatile int is function");
    static_assert(!lc::is_function<const volatile int>::value, "const volatile int is function");

    static_assert(!lc::is_function<int[]>::value, "int[] is not function");
    static_assert(!lc::is_function<int[5]>::value, "int[5] is not function");

    static_assert(!lc::is_function<int*>::value, "int* is not function");
    static_assert(!lc::is_function<int&>::value, "int& is not function");
    static_assert(!lc::is_function<int&&>::value, "int&& is not function");

    static_assert(lc::is_function<int()>::value, "int() is function");

    static_assert(lc::is_function<int(int)>::value, "int(int) is function");
}

// is reference
TEST(TypeTraits, is_reference) {
    static_assert(!lc::is_reference<int>::value, "int is reference");
    static_assert(!lc::is_reference<const int>::value, "const int is reference");
    static_assert(!lc::is_reference<volatile int>::value, "volatile int is reference");
    static_assert(!lc::is_reference<const volatile int>::value, "const volatile int is reference");

    static_assert(!lc::is_reference<int[]>::value, "int[] is not reference");
    static_assert(!lc::is_reference<int[5]>::value, "int[5] is not reference");

    static_assert(!lc::is_reference<int*>::value, "int* is not reference");
    static_assert(lc::is_reference<int&>::value, "int& is reference");
    static_assert(lc::is_reference<int&&>::value, "int&& is reference");
}

// is pointer
TEST(TypeTraits, is_pointer) {
    static_assert(!lc::is_pointer<int>::value, "int is pointer");
    static_assert(!lc::is_pointer<const int>::value, "const int is pointer");
    static_assert(!lc::is_pointer<volatile int>::value, "volatile int is pointer");
    static_assert(!lc::is_pointer<const volatile int>::value, "const volatile int is pointer");

    static_assert(!lc::is_pointer<int[]>::value, "int[] is not pointer");
    static_assert(!lc::is_pointer<int[5]>::value, "int[5] is not pointer");

    static_assert(lc::is_pointer<int*>::value, "int* is pointer");
    static_assert(lc::is_pointer<int* const>::value, "int* const is pointer");
    static_assert(lc::is_pointer<int* volatile>::value, "int* volatile is pointer");
    static_assert(lc::is_pointer<int* const volatile>::value, "int* const volatile is pointer");

    static_assert(!lc::is_pointer<int&>::value, "int& is not pointer");
    static_assert(!lc::is_pointer<int&&>::value, "int&& is not pointer");
}

// is member object pointer
TEST(TypeTraits, is_member_object_pointer) {
    struct S {
        int i;
    };

    static_assert(!lc::is_member_object_pointer<int>::value, "int is member object pointer");
    static_assert(!lc::is_member_object_pointer<const int>::value, "const int is member object pointer");
    static_assert(!lc::is_member_object_pointer<volatile int>::value, "volatile int is member object pointer");
    static_assert(!lc::is_member_object_pointer<const volatile int>::value, "const volatile int is member object pointer");

    static_assert(!lc::is_member_object_pointer<int[]>::value, "int[] is not member object pointer");
    static_assert(!lc::is_member_object_pointer<int[5]>::value, "int[5] is not member object pointer");

    static_assert(!lc::is_member_object_pointer<int*>::value, "int* is not member object pointer");
    static_assert(!lc::is_member_object_pointer<int&>::value, "int& is not member object pointer");
    static_assert(!lc::is_member_object_pointer<int&&>::value, "int&& is not member object pointer");

    static_assert(lc::is_member_object_pointer<int S::*>::value, "int S::* is member object pointer");
    static_assert(lc::is_member_object_pointer<int S::* const>::value, "int S::* const is member object pointer");
    static_assert(lc::is_member_object_pointer<int S::* volatile>::value, "int S::* volatile is member object pointer");
    static_assert(lc::is_member_object_pointer<int S::* const volatile>::value, "int S::* const volatile is member object pointer");
}

// is member function pointer
TEST(TypeTraits, is_member_function_pointer) {
    struct S {
        void f();
    };

    static_assert(!lc::is_member_function_pointer<int>::value, "int is member function pointer");
    static_assert(!lc::is_member_function_pointer<const int>::value, "const int is member function pointer");
    static_assert(!lc::is_member_function_pointer<volatile int>::value, "volatile int is member function pointer");
    static_assert(!lc::is_member_function_pointer<const volatile int>::value, "const volatile int is member function pointer");

    static_assert(!lc::is_member_function_pointer<int[]>::value, "int[] is not member function pointer");
    static_assert(!lc::is_member_function_pointer<int[5]>::value, "int[5] is not member function pointer");

    static_assert(!lc::is_member_function_pointer<int*>::value, "int* is not member function pointer");
    static_assert(!lc::is_member_function_pointer<int&>::value, "int& is not member function pointer");
    static_assert(!lc::is_member_function_pointer<int&&>::value, "int&& is not member function pointer");

    static_assert(lc::is_member_function_pointer<void (S::*)()>::value, "void (S::*)() is member function pointer");
    static_assert(lc::is_member_function_pointer<void (S::*)() const>::value, "void (S::*)() const is member function pointer");
    static_assert(lc::is_member_function_pointer<void (S::*)() volatile>::value, "void (S::*)() volatile is member function pointer");
    static_assert(lc::is_member_function_pointer<void (S::*)() const volatile>::value, "void (S::*)() const volatile is member function pointer");
}
