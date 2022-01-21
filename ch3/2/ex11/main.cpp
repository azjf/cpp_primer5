#include <iostream>

int main()
{
    const std::string s = "Keep out!";
    for (auto &c : s) {
        //c = 'X';
    }
    return 0;
}
