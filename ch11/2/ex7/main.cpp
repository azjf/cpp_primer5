#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::map<std::string, std::vector<std::string>> families {
        {"hello", {"world1", "world2"}} };
    families["hi"] = {"world1", "world2"};
    families["hello"].push_back("world3");
    std::cout << families["hello"].size() << " "
        << families["hi"].size() << std::endl;
    return 0;
}
