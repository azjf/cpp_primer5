#include <iostream>

int main()
{
    auto old_state = std::cin.rdstate();
    std::cin.clear();
    //process_input(std::cin);
    std::cin.setstate(old_state);

    std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.badbit);

    std::cout << "hi!" << std::endl;
    std::cout << "hi!" << std::flush;
    std::cout << "hi!" << std::ends;

    std::cout << std::unitbuf;
    std::cout << std::nounitbuf;

    std::cin.tie(&std::cout);
    std::ostream *old_tie = std::cin.tie(nullptr);
    std::cin.tie(&std::cerr);
    std::cin.tie(old_tie);
    return 0;
}
