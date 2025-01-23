#include <gtest/gtest.h>

#include "type_traits.h"

// ---------------------------------------------
// Primary type categories

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
    static_assert(lc::is_same<lc::remove_cv<int>::type, int>::value,
                  "remove_cv<int> is same as int");
    static_assert(lc::is_same<lc::remove_cv<const int>::type, int>::value,
                  "remove_cv<const int> is same as int");
    static_assert(lc::is_same<lc::remove_cv<volatile int>::type, int>::value,
                  "remove_cv<volatile int> is same as int");
    static_assert(
        lc::is_same<lc::remove_cv<const volatile int>::type, int>::value,
        "remove_cv<const volatile int> is same as int");

    static_assert(lc::is_same<lc::remove_const<int>::type, int>::value,
                  "remove_const<int> is same as int");
    static_assert(lc::is_same<lc::remove_const<const int>::type, int>::value,
                  "remove_const<const int> is same as int");
    static_assert(
        lc::is_same<lc::remove_const<volatile int>::type, volatile int>::value,
        "remove_const<volatile int> is same as volatile int");
    static_assert(lc::is_same<lc::remove_const<const volatile int>::type,
                              volatile int>::value,
                  "remove_const<const volatile int> is same as volatile int");

    static_assert(lc::is_same<lc::remove_volatile<int>::type, int>::value,
                  "remove_volatile<int> is same as int");
    static_assert(
        lc::is_same<lc::remove_volatile<const int>::type, const int>::value,
        "remove_volatile<const int> is same as const int");
    static_assert(
        lc::is_same<lc::remove_volatile<volatile int>::type, int>::value,
        "remove_volatile<volatile int> is same as int");
    static_assert(lc::is_same<lc::remove_volatile<const volatile int>::type,
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
    static_assert(!lc::is_array<volatile int>::value,
                  "volatile int is not array");
    static_assert(!lc::is_array<const volatile int>::value,
                  "const volatile int is not array");
}

// is enum
TEST(TypeTraits, is_enum) {
    static_assert(!lc::is_enum<int>::value, "int is enum");
    static_assert(!lc::is_enum<const int>::value, "const int is enum");
    static_assert(!lc::is_enum<volatile int>::value, "volatile int is enum");
    static_assert(!lc::is_enum<const volatile int>::value,
                  "const volatile int is enum");

    static_assert(!lc::is_enum<int[]>::value, "int[] is not enum");
    static_assert(!lc::is_enum<int[5]>::value, "int[5] is not enum");

    enum E {
        e1,
        e2
    };

    static_assert(lc::is_enum<E>::value, "E is enum");
}

// is union
TEST(TypeTraits, is_union) {
    static_assert(!lc::is_union<int>::value, "int is union");
    static_assert(!lc::is_union<const int>::value, "const int is union");
    static_assert(!lc::is_union<volatile int>::value, "volatile int is union");
    static_assert(!lc::is_union<const volatile int>::value,
                  "const volatile int is union");

    static_assert(!lc::is_union<int[]>::value, "int[] is not union");
    static_assert(!lc::is_union<int[5]>::value, "int[5] is not union");

    union U {
        int    i;
        double d;
    };

    static_assert(lc::is_union<U>::value, "U is union");
}

// is class
TEST(TypeTraits, is_class) {
    static_assert(!lc::is_class<int>::value, "int is class");
    static_assert(!lc::is_class<const int>::value, "const int is class");
    static_assert(!lc::is_class<volatile int>::value, "volatile int is class");
    static_assert(!lc::is_class<const volatile int>::value,
                  "const volatile int is class");

    static_assert(!lc::is_class<int[]>::value, "int[] is not class");
    static_assert(!lc::is_class<int[5]>::value, "int[5] is not class");

    class C {};

    static_assert(lc::is_class<C>::value, "C is class");
}

// is function
TEST(TypeTraits, is_function) {
    static_assert(!lc::is_function<int>::value, "int is function");
    static_assert(!lc::is_function<const int>::value, "const int is function");
    static_assert(!lc::is_function<volatile int>::value,
                  "volatile int is function");
    static_assert(!lc::is_function<const volatile int>::value,
                  "const volatile int is function");

    static_assert(!lc::is_function<int[]>::value, "int[] is not function");
    static_assert(!lc::is_function<int[5]>::value, "int[5] is not function");

    static_assert(!lc::is_function<int *>::value, "int* is not function");
    static_assert(!lc::is_function<int &>::value, "int& is not function");
    static_assert(!lc::is_function<int &&>::value, "int&& is not function");

    static_assert(lc::is_function<int()>::value, "int() is function");

    static_assert(lc::is_function<int(int)>::value, "int(int) is function");
}

// is reference
TEST(TypeTraits, is_reference) {
    static_assert(!lc::is_reference<int>::value, "int is reference");
    static_assert(!lc::is_reference<const int>::value,
                  "const int is reference");
    static_assert(!lc::is_reference<volatile int>::value,
                  "volatile int is reference");
    static_assert(!lc::is_reference<const volatile int>::value,
                  "const volatile int is reference");

    static_assert(!lc::is_reference<int[]>::value, "int[] is not reference");
    static_assert(!lc::is_reference<int[5]>::value, "int[5] is not reference");

    static_assert(!lc::is_reference<int *>::value, "int* is not reference");
    static_assert(lc::is_reference<int &>::value, "int& is reference");
    static_assert(lc::is_reference<int &&>::value, "int&& is reference");
}

// is pointer
TEST(TypeTraits, is_pointer) {
    static_assert(!lc::is_pointer<int>::value, "int is pointer");
    static_assert(!lc::is_pointer<const int>::value, "const int is pointer");
    static_assert(!lc::is_pointer<volatile int>::value,
                  "volatile int is pointer");
    static_assert(!lc::is_pointer<const volatile int>::value,
                  "const volatile int is pointer");

    static_assert(!lc::is_pointer<int[]>::value, "int[] is not pointer");
    static_assert(!lc::is_pointer<int[5]>::value, "int[5] is not pointer");

    static_assert(lc::is_pointer<int *>::value, "int* is pointer");
    static_assert(lc::is_pointer<int * const>::value, "int* const is pointer");
    static_assert(lc::is_pointer<int * volatile>::value,
                  "int* volatile is pointer");
    static_assert(lc::is_pointer<int * const volatile>::value,
                  "int* const volatile is pointer");

    static_assert(!lc::is_pointer<int &>::value, "int& is not pointer");
    static_assert(!lc::is_pointer<int &&>::value, "int&& is not pointer");
}

// is member object pointer
TEST(TypeTraits, is_member_object_pointer) {
    struct S {
        int i;
    };

    static_assert(!lc::is_member_object_pointer<int>::value,
                  "int is member object pointer");
    static_assert(!lc::is_member_object_pointer<const int>::value,
                  "const int is member object pointer");
    static_assert(!lc::is_member_object_pointer<volatile int>::value,
                  "volatile int is member object pointer");
    static_assert(!lc::is_member_object_pointer<const volatile int>::value,
                  "const volatile int is member object pointer");

    static_assert(!lc::is_member_object_pointer<int[]>::value,
                  "int[] is not member object pointer");
    static_assert(!lc::is_member_object_pointer<int[5]>::value,
                  "int[5] is not member object pointer");

    static_assert(!lc::is_member_object_pointer<int *>::value,
                  "int* is not member object pointer");
    static_assert(!lc::is_member_object_pointer<int &>::value,
                  "int& is not member object pointer");
    static_assert(!lc::is_member_object_pointer<int &&>::value,
                  "int&& is not member object pointer");

    static_assert(lc::is_member_object_pointer<int S::*>::value,
                  "int S::* is member object pointer");
    static_assert(lc::is_member_object_pointer<int S::* const>::value,
                  "int S::* const is member object pointer");
    static_assert(lc::is_member_object_pointer<int S::* volatile>::value,
                  "int S::* volatile is member object pointer");
    static_assert(lc::is_member_object_pointer<int S::* const volatile>::value,
                  "int S::* const volatile is member object pointer");
}

// is member function pointer
TEST(TypeTraits, is_member_function_pointer) {
    struct S {
        void f();
    };

    static_assert(!lc::is_member_function_pointer<int>::value,
                  "int is member function pointer");
    static_assert(!lc::is_member_function_pointer<const int>::value,
                  "const int is member function pointer");
    static_assert(!lc::is_member_function_pointer<volatile int>::value,
                  "volatile int is member function pointer");
    static_assert(!lc::is_member_function_pointer<const volatile int>::value,
                  "const volatile int is member function pointer");

    static_assert(!lc::is_member_function_pointer<int[]>::value,
                  "int[] is not member function pointer");
    static_assert(!lc::is_member_function_pointer<int[5]>::value,
                  "int[5] is not member function pointer");

    static_assert(!lc::is_member_function_pointer<int *>::value,
                  "int* is not member function pointer");
    static_assert(!lc::is_member_function_pointer<int &>::value,
                  "int& is not member function pointer");
    static_assert(!lc::is_member_function_pointer<int &&>::value,
                  "int&& is not member function pointer");

    static_assert(lc::is_member_function_pointer<void (S::*)()>::value,
                  "void (S::*)() is member function pointer");
    static_assert(lc::is_member_function_pointer<void (S::*)() const>::value,
                  "void (S::*)() const is member function pointer");
    static_assert(lc::is_member_function_pointer<void (S::*)() volatile>::value,
                  "void (S::*)() volatile is member function pointer");
    static_assert(
        lc::is_member_function_pointer<void (S::*)() const volatile>::value,
        "void (S::*)() const volatile is member function pointer");
}

// ---------------------------------------------
// Type properties

// has unique object representations
TEST(TypeTraits, has_unique_object_representations) {
    static_assert(lc::has_unique_object_representations<int>::value,
                  "int has unique object representations");
    static_assert(lc::has_unique_object_representations<const int>::value,
                  "const int has unique object representations");
    static_assert(lc::has_unique_object_representations<volatile int>::value,
                  "volatile int has unique object representations");
    static_assert(
        lc::has_unique_object_representations<const volatile int>::value,
        "const volatile int has unique object representations");

    static_assert(!lc::has_unique_object_representations<float>::value,
                  "float does not have unique object representations");
    static_assert(!lc::has_unique_object_representations<const float>::value,
                  "const float does not have unique object representations");
    static_assert(!lc::has_unique_object_representations<volatile float>::value,
                  "volatile float does not have unique object representations");
    static_assert(
        !lc::has_unique_object_representations<const volatile float>::value,
        "const volatile float does not have unique object representations");

    static_assert(!lc::has_unique_object_representations<float[]>::value,
                  "float[] does not have unique object representations");
    static_assert(!lc::has_unique_object_representations<float[5]>::value,
                  "float[5] does not have unique object representations");

    static_assert(lc::has_unique_object_representations<int *>::value,
                  "int* has unique object representations");
    static_assert(!lc::has_unique_object_representations<int &>::value,
                  "int& has unique object representations");
    static_assert(!lc::has_unique_object_representations<int &&>::value,
                  "int&& has unique object representations");

    static_assert(lc::has_unique_object_representations<float *>::value,
                  "float* has unique object representations");
    static_assert(!lc::has_unique_object_representations<float &>::value,
                  "float& does not have unique object representations");
    static_assert(!lc::has_unique_object_representations<float &&>::value,
                  "float&& does not have unique object representations");
}

// is abstract
TEST(TypeTraits, is_abstract) {
    class C {
    public:
        virtual void f() = 0;
    };

    static_assert(lc::is_abstract<C>::value, "C is abstract");

    class D : public C {
    public:
        void f() override {}
    };

    static_assert(!lc::is_abstract<D>::value, "D is not abstract");
}

// is aggregate
TEST(TypeTraits, is_aggregate) {
    struct S {
        int    i;
        double d;
    };

    static_assert(lc::is_aggregate<S>::value, "S is aggregate");

    struct T {
        int    i;
        double d;

    private:
        char c;
    };

    static_assert(!lc::is_aggregate<T>::value, "T is not aggregate");
}

// is bounded array
// unsupported

// is const
TEST(TypeTraits, is_const) {
    static_assert(!lc::is_const<int>::value, "int is const");
    static_assert(lc::is_const<const int>::value, "const int is const");
    static_assert(!lc::is_const<volatile int>::value, "volatile int is const");
    static_assert(lc::is_const<const volatile int>::value,
                  "const volatile int is const");
}

// is empty
TEST(TypeTraits, is_empty) {
    class C {};

    static_assert(lc::is_empty<C>::value, "C is empty");

    class D {
        int i;
    };

    static_assert(!lc::is_empty<D>::value, "D is not empty");
}

// is final
TEST(TypeTraits, is_final) {
    class C final {};

    static_assert(lc::is_final<C>::value, "C is final");

    class D {};

    static_assert(!lc::is_final<D>::value, "D is not final");
}

// is implicit lifetime
// unsupported

// is literal type
// unsupported

// is pod
TEST(TypeTraits, is_pod) {
    static_assert(lc::is_pod<int>::value, "int is pod");
    static_assert(lc::is_pod<const int>::value, "const int is pod");
    static_assert(lc::is_pod<volatile int>::value, "volatile int is pod");
    static_assert(lc::is_pod<const volatile int>::value,
                  "const volatile int is pod");

    static_assert(lc::is_pod<float>::value, "float is pod");
    static_assert(lc::is_pod<const float>::value, "const float is pod");
    static_assert(lc::is_pod<volatile float>::value, "volatile float is pod");
    static_assert(lc::is_pod<const volatile float>::value,
                  "const volatile float is pod");

    static_assert(lc::is_pod<int[]>::value, "int[] is pod");
    static_assert(lc::is_pod<int[5]>::value, "int[5] is pod");

    static_assert(lc::is_pod<int *>::value, "int* is pod");
    static_assert(!lc::is_pod<int &>::value, "int& is not pod");
    static_assert(!lc::is_pod<int &&>::value, "int&& is not pod");
}

// is polymorphic
TEST(TypeTraits, is_polymorphic) {
    class C {
    public:
        virtual void f() {}
    };

    static_assert(lc::is_polymorphic<C>::value, "C is polymorphic");

    class D {
    public:
        void f() {}
    };

    static_assert(!lc::is_polymorphic<D>::value, "D is not polymorphic");
}

// is scoped enum
// unsupported

// is signed
TEST(TypeTraits, is_signed) {
    static_assert(lc::is_signed<int>::value, "int is signed");
    static_assert(lc::is_signed<const int>::value, "const int is signed");
    static_assert(lc::is_signed<volatile int>::value, "volatile int is signed");
    static_assert(lc::is_signed<const volatile int>::value,
                  "const volatile int is signed");

    static_assert(!lc::is_signed<unsigned int>::value,
                  "unsigned int is signed");
    static_assert(!lc::is_signed<const unsigned int>::value,
                  "const unsigned int is signed");
    static_assert(!lc::is_signed<volatile unsigned int>::value,
                  "volatile unsigned int is signed");
    static_assert(!lc::is_signed<const volatile unsigned int>::value,
                  "const volatile unsigned int is signed");
}

// is standard layout
// unsupported

// is trivial
TEST(TypeTraits, is_trivial) {
    static_assert(lc::is_trivial<int>::value, "int is trivial");
    static_assert(lc::is_trivial<const int>::value, "const int is trivial");
    static_assert(lc::is_trivial<volatile int>::value,
                  "volatile int is trivial");
    static_assert(lc::is_trivial<const volatile int>::value,
                  "const volatile int is trivial");

    static_assert(lc::is_trivial<float>::value, "float is trivial");
    static_assert(lc::is_trivial<const float>::value, "const float is trivial");
    static_assert(lc::is_trivial<volatile float>::value,
                  "volatile float is trivial");
    static_assert(lc::is_trivial<const volatile float>::value,
                  "const volatile float is trivial");

    static_assert(lc::is_trivial<int[]>::value, "int[] is trivial");
    static_assert(lc::is_trivial<int[5]>::value, "int[5] is trivial");

    static_assert(lc::is_trivial<int *>::value, "int* is trivial");
    static_assert(!lc::is_trivial<int &>::value, "int& is not trivial");
    static_assert(!lc::is_trivial<int &&>::value, "int&& is not trivial");
}

// is trivially copyable
TEST(TypeTraits, is_trivially_copyable) {
    static_assert(lc::is_trivially_copyable<int>::value,
                  "int is trivially copyable");
    static_assert(lc::is_trivially_copyable<const int>::value,
                  "const int is trivially copyable");
    static_assert(lc::is_trivially_copyable<volatile int>::value,
                  "volatile int is trivially copyable");
    static_assert(lc::is_trivially_copyable<const volatile int>::value,
                  "const volatile int is trivially copyable");

    static_assert(lc::is_trivially_copyable<float>::value,
                  "float is trivially copyable");
    static_assert(lc::is_trivially_copyable<const float>::value,
                  "const float is trivially copyable");
    static_assert(lc::is_trivially_copyable<volatile float>::value,
                  "volatile float is trivially copyable");
    static_assert(lc::is_trivially_copyable<const volatile float>::value,
                  "const volatile float is trivially copyable");

    static_assert(lc::is_trivially_copyable<int[]>::value,
                  "int[] is trivially copyable");
    static_assert(lc::is_trivially_copyable<int[5]>::value,
                  "int[5] is trivially copyable");

    static_assert(lc::is_trivially_copyable<int *>::value,
                  "int* is trivially copyable");
    static_assert(!lc::is_trivially_copyable<int &>::value,
                  "int& is not trivially copyable");
    static_assert(!lc::is_trivially_copyable<int &&>::value,
                  "int&& is not trivially copyable");
}

// is unbounded array
// unsupported

// is unsigned
TEST(TypeTraits, is_unsigned) {
    static_assert(!lc::is_unsigned<int>::value, "int is unsigned");
    static_assert(!lc::is_unsigned<const int>::value, "const int is unsigned");
    static_assert(!lc::is_unsigned<volatile int>::value,
                  "volatile int is unsigned");
    static_assert(!lc::is_unsigned<const volatile int>::value,
                  "const volatile int is unsigned");

    static_assert(lc::is_unsigned<unsigned int>::value,
                  "unsigned int is unsigned");
    static_assert(lc::is_unsigned<const unsigned int>::value,
                  "const unsigned int is unsigned");
    static_assert(lc::is_unsigned<volatile unsigned int>::value,
                  "volatile unsigned int is unsigned");
    static_assert(lc::is_unsigned<const volatile unsigned int>::value,
                  "const volatile unsigned int is unsigned");
}

// is volatile
TEST(TypeTraits, is_volatile) {
    static_assert(!lc::is_volatile<int>::value, "int is volatile");
    static_assert(!lc::is_volatile<const int>::value, "const int is volatile");
    static_assert(lc::is_volatile<volatile int>::value,
                  "volatile int is volatile");
    static_assert(lc::is_volatile<const volatile int>::value,
                  "const volatile int is volatile");
}
