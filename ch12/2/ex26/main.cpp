#include <iostream>
#include <memory>
#include <iterator>

int main()
{
    size_t n = 10;
    std::allocator<std::string> alloc;
    const auto p = alloc.allocate(n);
    std::string s, *q = p;
    //while (std::cin >> s && q != p + n) {
    //    alloc.construct(q++, s);
    //}
    std::istream_iterator<std::string> in_it(std::cin), eof;
    std::uninitialized_copy(in_it, eof, p);

    const size_t size = q - p;
    while (q != p) {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, n);
    return 0;
}
