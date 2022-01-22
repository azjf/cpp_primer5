#include <iostream>
#include <vector>

template<typename T>
void print_vector(std::vector<T> &v);

int main()
{
    std::vector<int> v1;
    std::vector<int> v2(10);
    std::vector<int> v3(10, 42);
    std::vector<int> v4{10};
    std::vector<int> v5{10, 42};
    std::vector<std::string> v6{10};
    std::vector<std::string> v7{10, "hi"};

    print_vector<int>(v1);
    print_vector<int>(v2);
    print_vector<int>(v3);
    print_vector<int>(v4);
    print_vector<int>(v5);
    print_vector<std::string>(v6);
    print_vector<std::string>(v7);
    return 0;
}

template<typename T>
void print_vector(std::vector<T> &v) {
    if (v.empty()) {
        std::cout << "empty vector" << std::endl;
        return;
    }
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
