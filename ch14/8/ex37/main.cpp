#include <iostream>
#include <vector>
#include <algorithm>

class Equal
{
public:
    Equal() = default;
    Equal(int v) : val(v) {}
    bool operator()(int v) { return val == v; }

private:
    int val = 0;
};

int main()
{
    std::vector<int> ivec{1, 2, 3, 1, 2, 3};
    Equal equal(2);
    std::replace_if(ivec.begin(), ivec.end(), equal, 4);
    std::for_each(ivec.begin(), ivec.end(),
            [] (int num) { std::cout << num << " "; });
    std::cout << std::endl;
    return 0;
}
