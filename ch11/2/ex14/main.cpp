#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::map<std::string, std::vector<std::string>> families{
        {"hello", {"world1", "world2"}} };
    families["hi"] = {"world1", "world2"};
    families["hello"].push_back("world3");
    std::cout << families["hello"].size() << " "
        << families["hi"].size() << std::endl;

    std::vector<std::pair<std::string, std::vector<std::string>>> families2{
        {"hello", {"world1", "world2"}} };
    families2.push_back({"hi", {"world1", "world2"}});
    families2[0].second.push_back("world3");
    std::cout << families2[0].second.size() << " "
        << families2[1].second.size() << std::endl;
    return 0;
}
