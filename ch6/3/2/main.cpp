#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<std::string> process()
{
    std::string expected("expected"), actual("actual");
    if (expected.empty()) {
        return {};
    } else if (expected == actual) {
        return {"functionX", "okay"};
    } else {
        return {"functionX", expected, actual};
    }
}

int factorial(int val)
{
    if (val > 1) {
        return factorial(val - 1) * val;
    }
    return 1;
}

int main()
{
    process();

    bool some_failure = false;

    std::cout << factorial(5) << std::endl;

    if (some_failure) {
        return EXIT_FAILURE;
    } else {
        return EXIT_SUCCESS;
    }
}
