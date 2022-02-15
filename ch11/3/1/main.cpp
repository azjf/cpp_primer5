#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include "Sales_data.h"

int main()
{
    std::map<std::string, size_t> word_count {
        {"hello", 1},
        {"wolrd", 2} };

    std::set<std::string>::value_type v1;
    std::set<std::string>::key_type v2;
    std::map<std::string, int>::value_type v3;
    std::map<std::string, int>::key_type v4;
    std::map<std::string, int>::mapped_type v5;

    auto map_it = word_count.begin();
    std::cout << map_it->first;
    std::cout << " " << map_it->second << std::endl;
    //map_it->first = "new key";
    ++map_it->second;

    std::set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::set<int>::iterator set_it = iset.begin();
    if (set_it != iset.end()) {
        //*set_it = 42;
        std::cout << *set_it << std::endl;
    }

    auto map_it2 = word_count.cbegin();
    while (map_it2 != word_count.cend()) {
        std::cout << map_it2->first << " occurs "
            << map_it2->second << " times" << std::endl;
        ++map_it2;
    }

    std::vector<int> ivec = {2, 4, 6, 8, 2, 4, 6, 8};
    std::set<int> set2;
    set2.insert(ivec.cbegin(), ivec.cend());
    set2.insert({1, 3, 5, 7, 1, 3, 5, 7});

    std::string word("word");
    word_count.insert({word, 1});
    word_count.insert(std::make_pair(word, 1));
    word_count.insert(std::pair<std::string, size_t>(word, 1));
    word_count.insert(std::map<std::string, size_t>::value_type(word, 1));

    while (std::cin >> word) {
        auto ret = word_count.insert({word, 1});
        std::pair<std::map<std::string, size_t>::iterator, bool> ret2 =
            word_count.insert(std::make_pair(word, 1));
        if (!ret.second) {
            ++ret.first->second;
        }
    }

    std::multimap<std::string, std::string> authors;
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    authors.insert({"Barth, John", "Lost in the Funhouse"});

    std::string removal_word("hello");
    if (word_count.erase(removal_word)) {
        std::cout << "ok: " << removal_word << " removed\n";
    } else {
        std::cout << "oops: " << removal_word << " not found!\n";
    }

    auto cnt = authors.erase("Barth, John");
    std::cout << cnt << std::endl;

    word_count["Anna"] = 1;
    std::cout << word_count["Anna"] << std::endl;
    ++word_count["Anna"];
    std::cout << word_count["Anna"] << std::endl;
    std::cout << word_count["Anna1"] << std::endl;

    iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    iset.find(1);
    iset.find(11);
    iset.count(1);
    iset.count(11);

    if (word_count.find("foobar") == word_count.end()) {
        std::cout << "foobar is not in the map" << std::endl;
    }

    authors.insert({"Alain de Botton", "hello"});
    authors.insert({"Alain de Botton", "world"});
    std::string search_item("Alain de Botton");
    auto entries = authors.count(search_item);
    auto iter = authors.find(search_item);
    while (entries) {
        std::cout << iter->second << std::endl;
        ++iter;
        --entries;
    }

    for (auto beg = authors.lower_bound(search_item),
            end = authors.upper_bound(search_item);
            beg != end; ++beg) {
        std::cout << beg->second << std::endl;
    }

    for (auto pos = authors.equal_range(search_item);
            pos.first != pos.second; ++pos.first) {
        std::cout << pos.first->second << std::endl;
    }
        
    return 0;
}
