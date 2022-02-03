#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vi{1, 2, 3};
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            //++iter;
        }
        ++iter;
    }
    return 0;
}
