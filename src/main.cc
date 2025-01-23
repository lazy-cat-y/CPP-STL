
#include "a.h"
#include <type_traits>

int main() {
    std::is_member_object_pointer<int>::value;
    std::is_member_function_pointer<int>::value;
    return 0;
}