#include <fstream>
#include <vector>

int main()
{
    std::vector<std::string> svec;
    std::ifstream input("ifile");
    if (!input) {
        return -1;
    }

    std::string word;
    while (std::getline(input, word)) {
        svec.push_back(word);
    }
    return 0;
}
