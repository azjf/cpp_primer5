#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> flst{1, 2, 3, 4};
    auto pre = flst.before_begin();
    auto cur = flst.begin();
    while (cur != flst.end()) {
        if (*cur % 2) {
            flst.erase_after(pre);
        } else {
            pre = cur;
            ++cur;
        }
    }
    return 0;
}
