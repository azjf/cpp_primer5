#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v1{1, 2, 3}, v2;
    std::remove_if(v1.begin(), v1.end(),
            [] (int i) { return i % 2; });
    std::remove_copy_if(v1.begin(), v1.end(), std::back_inserter(v2),
            [] (int i) { return i % 2; });
    return 0;
}
