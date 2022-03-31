#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <cstring>
#include "Blob.h"
#include "BlobPtr.h"

int main()
{
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<const char *> w = {"now", "is", "the", "time"};
    Blob<int> a1(std::begin(ia), std::end(ia));
    Blob<int> a2(vi.begin(), vi.end());
    Blob<std::string> a3(w.begin(), w.end());
    return 0;
}
