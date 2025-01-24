

#include <iterator>
#include <memory>
int main() {
    std::allocator<int> alloc;
    std::iterator_traits<int*> traits;
    std::reverse_iterator<int*> rev_iter;
    std::move_iterator<int*> move_iter;
    return 0;
}