#include <iostream>
#include <vector>

void f(size_t n)
{
    std::vector<std::string> svec;
    svec.reserve(1024);
    std::cout << " svec: size: " << svec.size()
        << " capacity: " << svec.capacity() << std::endl;

    //std::string word;
    //while (std::cin >> word) {
    //    svec.push_back(word);
    //}

    std::string word("word");
    for (size_t i = 0; i != n; ++i) {
        svec.push_back(word);
    }
    std::cout << " svec: size: " << svec.size()
        << " capacity: " << svec.capacity() << std::endl;

    svec.resize(svec.size() + svec.size() / 2);
    std::cout << " svec: size: " << svec.size()
        << " capacity: " << svec.capacity() << std::endl;
}

int main()
{
    f(256);
    std::cout << std::endl;
    f(512);
    std::cout << std::endl;
    f(1000);
    std::cout << std::endl;
    f(1048);
    return 0;
}
