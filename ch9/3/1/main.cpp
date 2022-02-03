#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include "Sales_data.h"

int main()
{
    std::list<int> ilist;
    for (size_t ix = 0; ix != 4; ++ix) {
        ilist.push_front(ix);
    }

    std::vector<std::string> svec;
    std::list<std::string> slist;

    slist.insert(slist.begin(), "Hello!");
    slist.push_front("Hello!");
    svec.insert(svec.begin(), "Hello!");

    svec.insert(svec.end(), 10, "Anna");

    std::vector<std::string> v = {"quasi", "simba", "frollo", "scar"};
    slist.insert(slist.begin(), v.end() - 2, v.end());
    slist.insert(slist.cend(), {"these", "words", "will",
            "go", "at", "the", "end"});
    //slist.insert(slist.begin(), slist.begin(), slist.end());

    std::list<std::string> lst;
    std::string word;
    auto iter = lst.begin();
    while (std::cin >> word) {
        iter = lst.insert(iter, word);
    }

    std::list<Sales_data> c;
    c.emplace_back("978-0590353403", 25, 15.99);
    //c.push_back("978-0590353403", 25, 15.99);
    c.push_back(Sales_data("978-0590353403", 25, 15.99));
    c.emplace_back();
    auto iter2 = c.cend();
    c.emplace(iter2, "999-999999999");
    c.emplace_front("978-0590353403", 25, 15.99);

    std::list<int> c2{1, 2, 3, 4};
    if (!c.empty()) {
        auto val = *c.begin(), val2 = c.front();
        auto last = c.end();
        auto val3 = *(--last);
        auto val4 = c.back();
    }

    if (!c.empty()) {
        c2.front() = 42;
        auto &v = c2.back();
        v = 1024;
        auto v2 = c2.back();
        v2 = 0;
    }

    std::vector<std::string> svec2;
    //std::cout << svec2[0];
    //std::cout << svec2.at(0);
    
    std::list<int> lst2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = lst2.begin();
    while (it != lst2.end()) {
        if (*it % 2) {
            it = lst2.erase(it);
        } else {
            ++it;
        }
    }

    slist.clear();
    slist.erase(slist.begin(), slist.end());

    std::forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2) {
            curr = flst.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }
    }

    std::list<int> ilist2(10, 42);
    ilist2.resize(15);
    ilist2.resize(25, -1);
    ilist2.resize(5);

    std::vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter3 = vi.begin();
    while (iter3 != vi.end()) {
        if (*iter3 % 2) {
            iter3 = vi.insert(iter3, *iter3);
            iter3 += 2;
        } else {
            iter3 = vi.erase(iter3);
        }
    }

    std::vector<int> v2(vi);
    auto begin = v2.begin(), end = v2.end();
    //while (begin != end) {
    while (begin != v2.end()) {
        ++begin;
        begin = v2.insert(begin, 42);
        ++begin;
    }
    return 0;
}

void pluralize(size_t cnt, std::string &word) {
    if (cnt > 1) {
        word.push_back('s');
        //word += s;
    }
}
