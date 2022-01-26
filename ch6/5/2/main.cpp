#include <iostream>
#include <cassert>

void print(const int ia[], size_t size)
{
#ifndef NDEBUG
    std::cerr << __func__ << ": array size is " << size << std::endl;
#endif
}

int main()
{
    std::string word("foo");
    decltype(word.size()) threshold = 1;
    assert(word.size() > threshold);
    //assert(word.size() > 10);

    const int ia[]{1, 2, 3};
    print(ia, 3);

    threshold = 10;
    if (word.size() < threshold) {
        std::cerr << "Error: " << __FILE__
            << " : in function " << __func__
            << " at line " << __LINE__ << std::endl
            << "        Compiled on " << __DATE__
            << " at " << __TIME__ << std::endl
            << "        Word read was \"" << word
            << "\": Length too short" << std::endl;
    }
    return 0;
}
