#include <iostream>

int main()
{
    const char *cp = "Hello World!!!";
    char noNull[] = {'H', 'i'};
    std::string s1(cp);
    std::string s2(noNull, 2);
    //std::string s3(noNull);
    std::string s4(cp + 6, 5);
    std::string s5(s1, 6, 5);
    std::string s6(s1, 6);
    std::string s7(s1, 6, 20);
    //std::string s8(s1, 16);

    std::string s("hello world");
    s2 = s.substr(0, 5);
    std::string s3 = s.substr(6);
    s4 = s.substr(6, 11);
    //s5 = s.substr(12);

    s.insert(s.size(), 5, '!');
    s.erase(s.size() - 5, 5);

    const char *cp2 = "Stately, pump Buck";
    s.assign(cp, 7);
    s.insert(s.size(), cp2 + 7);

    s = "some string", s2 = "some other string";
    s.insert(0, s2);
    s.insert(0, s2, 0, s2.size());

    s = "C++ Primer", s2 = s;
    s.insert(s.size(), " 4th Ed.");
    s2.append(" 4th Ed.");
    s.erase(11, 3);
    s.insert(11, "5th");
    s2.replace(11, 3, "Fifth");

    std::string name("AnnaBelle");
    auto pos1 = name.find("Anna");
    std::string lowercase("annabelle");
    pos1 = lowercase.find("Anna");
    std::string numbers("0123456789"), name2("r2d2");
    auto pos = name.find_first_not_of(numbers);
    std::string dept("03714p3");
    pos = dept.find_first_not_of(numbers);

    name = name2;
    pos = 0;
    while ((pos = name.find_first_of(numbers, pos)) != std::string::npos) {
        std::cout << "found number at index: " << pos
            << " element is " << name[pos] << std::endl;
        ++pos;
    }

    std::string river("Mississippi");
    auto first_pos = river.find("is");
    auto last_pos = river.rfind("is");

    int i = 42;
    s = std::to_string(i);
    double d = std::stod(s);

    s2 = "pi = 3.14";
    d = std::stod(s2.substr(s2.find_first_of("+-.0123456789")));
    //std::stod("a1234");
    std::stod("1234b");
    return 0;
}
