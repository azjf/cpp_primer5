#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>

int main()
{
    std::vector<std::vector<std::string>> lines;
    std::list<std::string>::iterator iter;
    std::vector<int>::difference_type count;

    std::list<std::string> a = {"Milton", "Shakespeare", "Austen"};
    auto it1 = a.begin();
    auto it2 = a.rbegin();
    auto it3 = a.cbegin();
    auto it4 = a.crbegin();

    std::list<std::string>::iterator it5 = a.begin();
    std::list<std::string>::const_iterator it6 = a.begin();
    auto it7 = a.begin();
    auto it8 = a.cbegin();

    std::list<std::string> authors = {"Milton", "Shakespeare", "Austen"};
    std::vector<const char *> articles = {"a", "an", "the"};
    std::list<std::string> list2(authors);
    //std::deque<std::string> authList(authors);
    //std::vector<std::string> words(articles);
    std::forward_list<std::string> words(articles.begin(), articles.end());
    auto it = authors.end();
    std::deque<std::string> authList(authors.begin(), it);

    std::vector<int> ivec(10, -1);
    std::list<std::string> svec(10, "hi!");
    std::forward_list<int> ivecc(10);
    std::deque<std::string> svecc(10);

    std::array<int, 10>::size_type i;
    //std::array<int>::size_type j;

    std::array<int, 10> ia1;
    std::array<int, 10> ia2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> ia3 = {42};

    int digs[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //int cpy[10] = digs;
    std::array<int, 10> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> copy = digits;

    std::array<int, 10> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2 = {0};
    a1 = a2;
    a2 = {0};

    std::list<std::string> names;
    std::vector<const char *> oldstyle;
    //names = oldstyle;
    names.assign(oldstyle.cbegin(), oldstyle.cbegin());

    std::list<std::string> slist1(1);
    slist1.assign(10, "Hiya!");
    slist1.clear();
    slist1.insert(slist1.begin(), 10, "Hiya!");

    std::vector<std::string> svec1(10);
    std::vector<std::string> svec2(24);
    std::swap(svec1, svec2);
    return 0;
}
