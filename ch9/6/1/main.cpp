#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>

int main()
{
    std::deque<int> deq{1, 2, 3};
    std::stack<int> stk(deq);

    std::vector<std::string> svec{"hello", "world"};
    std::stack<std::string, std::vector<std::string>> str_stk;
    std::stack<std::string, std::vector<std::string>> str_stk2(svec);

    std::stack<int> intStack;
    for (size_t ix = 0; ix != 10; ++ix) {
        intStack.push(ix);
        //intStack.push_back(ix);
    }
    while (!intStack.empty()) {
        int value = intStack.top();
        intStack.pop();
    }
    return 0;
}
