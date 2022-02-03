#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<std::string> flst{"hello", "world"};
    std::string s1("hello"), s2("hi");
    auto pre = flst.before_begin(), cur = flst.begin();
    while (cur != flst.end()) {
        if (*cur == s1) {
            flst.insert_after(cur, s2);
            break;
        } else {
            pre = cur;
            ++cur;
        }
    }
    if (cur == flst.end()) {
        flst.insert_after(pre, s2);
    }
    return 0;
}
