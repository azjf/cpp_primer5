#include <iostream>
#include <list>
#include <forward_list>

int main()
{
    std::list<int> ilist{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = ilist.begin();
    while (iter != ilist.end()) {
        if (*iter % 2) {
            iter = ilist.insert(iter, *iter);
            ++iter;
            ++iter;
        } else {
            iter = ilist.erase(iter);
        }
    }

    std::forward_list<int> iflist{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto pre = iflist.before_begin();
    auto cur = iflist.begin();
    while (cur != iflist.end()) {
        if (*cur % 2) {
            cur = iflist.insert_after(cur, *cur);
            pre = cur;
            ++cur;
        } else {
            cur = iflist.erase_after(pre);
        }
    }
    return 0;
}
