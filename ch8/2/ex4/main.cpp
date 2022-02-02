#include <fstream>
#include <vector>

int main()
{
    std::vector<std::string> svec;
    std::ifstream input("ifile");
    if (!input) {
        return -1;
    }

    std::string line;
    while (std::getline(input, line)) {
        svec.push_back(line);
    }
    return 0;
}
