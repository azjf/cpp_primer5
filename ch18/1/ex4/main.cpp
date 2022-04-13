#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

int main()
{
    try {
        throw std::overflow_error("e");
    } catch (std::overflow_error eobj) {
        std::cout << "overflow_error" << std::endl;
    } catch (const std::runtime_error &re) {
        std::cout << "runtime_error" << std::endl;
    } catch (std::exception) {
        std::cout << "exception" << std::endl;
    }
    return 0;
}
