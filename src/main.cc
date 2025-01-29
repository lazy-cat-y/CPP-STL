

#include <iterator>
#include <memory>
#include <sstream>

#include "temp.h"

int main() {
    std::allocator<int>           alloc;
    std::iterator_traits<int *>   traits;
    std::reverse_iterator<int *>  rev_iter;
    std::move_iterator<int *>     move_iter;
    std::istream_iterator<int>    istream_iter;
    std::istringstream            in {"Hello, world"};
    std::istreambuf_iterator<char> it {in}, end;
    return 0;
}
