#include <iostream>

/*
 * A simple main function:
 * Read two numbers from stdin, and output their sum
 */
int main()
{
    // Hint user to enter two number
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;     // to save numbers read from stdin to variables
    std::cin >> v1 >> v2;   // read numbers from stdin
    std::cout << "The sum of " << v1 << " and " << v2
        << " is " << v1 + v2 << std::endl;
    return 0;
}
