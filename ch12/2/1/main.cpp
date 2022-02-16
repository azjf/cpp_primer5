#include <iostream>
#include <memory>
#include <vector>

int main()
{
    int *pia = new int[5];
    typedef int arrT[42];
    int *p = new arrT;
    p = new int[42];

    {
    int *pia = new int[10];
    int *pia2 = new int[10]();
    std::string *psa = new std::string[10];
    std::string *psa2 = new std::string[10]();
    
    int *pia3 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::string *psa3 = new std::string[10]{"a", "an", "the",
        std::string(3, 'x')};
    
    char arr[0];
    char *cp = new char[0];

    typedef int arrT[42];
    int *p = new arrT;
    delete[] p;

    std::unique_ptr<int []> up(new int[10]);
    for (size_t i = 0; i != 10; ++i) {
        up[i] = i;
    }
    up.release();

    std::shared_ptr<int> sp(new int[10], [] (int *p) { delete[] p; });
    for (size_t i = 0; i != 10; ++i) {
        *(sp.get() + i) = i;
        (sp.get())[i] = i;
        sp.get()[i] = i;
    }
    sp.reset();
    }

    {
    int n = 10;
    std::string *const p = new std::string[n];
    std::string s;
    std::string *q = p;
    while (std::cin >> s && q != p + n) {
        *q++ = s;
    }
    const size_t size = q - p;
    }

    {
    size_t n = 10;
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(n);
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hi");
    std::cout << *p << std::endl;
    //std::cout << *q << std::endl;
    while (q != p) {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, n);
    }

    {
    std::vector<int> vi{1, 2, 3, 4};
    std::allocator<int> alloc;
    auto p = alloc.allocate(vi.size() * 2);
    auto q = std::uninitialized_copy(vi.begin(), vi.end(), p);
    std::uninitialized_fill_n(q, vi.size(), 42);
    }
    return 0;
}
