#include <iostream>
#include <cstring>

int main()
{
    const char ca1[] = "hello", ca2[] = " world";
    char result[12];
    std::strcpy(result, ca1);
    std::strcat(result, ca2);
    std::cout << result << std::endl;
    return 0;
}
