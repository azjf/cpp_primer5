#include <ios>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <random>
#include <ctime>

bool get_status() { return true; }

int main()
{
    std::cout << "default bool values: " << true << " " << false
        << "\nalpha bool values: " << std::boolalpha
        << true << " " << false << std::endl;
    bool bool_val = get_status();

    std::cout << std::boolalpha << bool_val << std::noboolalpha << std::endl;

    std::cout << "default: " << 20 << " " << 1024 << std::endl;
    std::cout << "octal: " << std::oct << 20 << " " << 1024 << std::endl;
    std::cout << "hex: " << std::hex << 20 << " " << 1024 << std::endl;
    std::cout << "decimal: " << std::dec << 20 << " " << 1024 << std::endl;

    std::cout << std::showbase;
    std::cout << "default: " << 20 << " " << 1024 << std::endl;
    std::cout << "in octal: " << std::oct << 20 << " " << 1024 << std::endl;
    std::cout << "in hex: " << std::hex << 20 << " " << 1024 << std::endl;
    std::cout << "in decimal: " << std::dec << 20 << " " << 1024 << std::endl;
    std::cout << std::noshowbase;

    std::cout << std::uppercase << std::showbase << std::hex
        << "printed in hexdecimal: " << 20 << " " << 1024
        << std::nouppercase << std::noshowbase << std::dec << std::endl;

    std::cout << "Precision: " << std::cout.precision()
        << ", Value: " << std::sqrt(2.0) << std::endl;
    std::cout.precision(12);
    std::cout << "Precision: " << std::cout.precision()
        << ", Value: " << std::sqrt(2.0) << std::endl;
    std::cout << std::setprecision(3);
    std::cout << "Precision: " << std::cout.precision()
        << ", Value: " << std::sqrt(2.0) << std::endl;

    std::cout << "default format: " << 100 * std::sqrt(2.0) << '\n'
        << "scientific: " << std::scientific << 100 * std::sqrt(2.0) << '\n'
        << "fixed decimal: " << std::fixed << 100 * std::sqrt(2.0) << '\n'
        << "hexadecimal: " << std::hexfloat << 100 * std::sqrt(2.0) << '\n'
        << "use defaults: " << std::defaultfloat << 100 * std::sqrt(2.0)
        << "\n\n";

    std::cout << 10.0 << std::endl;
    std::cout << std::showpoint << 10.0 << std::noshowpoint << std::endl;

    int i = -16;
    double d = 3.14159;
    std::cout << "i: " << std::setw(12) << i << "next col" << '\n'
        << "d: " << std::setw(12) << d << "next col" << '\n';
    std::cout << std::left
        << "i: " << std::setw(12) << i << "next col" << '\n'
        << "d: " << std::setw(12) << d << "next col" << '\n'
        << std::right;
    std::cout << std::right
        << "i: " << std::setw(12) << i << "next col" << '\n'
        << "d: " << std::setw(12) << d << "next col" << '\n';
    std::cout << std::internal
        << "i: " << std::setw(12) << i << "next col" << '\n'
        << "d: " << std::setw(12) << d << "next col" << '\n';
    std::cout << std::setfill('#')
        << "i: " << std::setw(12) << i << "next col" << '\n'
        << "d: " << std::setw(12) << d << "next col" << '\n'
        << std::setfill(' ');

    char ch;
    while (std::cin >> ch) {
        std::cout << ch;
    }
    return 0;
}
