#include <iostream>
#include <vector>

int main()
{
    const std::vector<std::string> scores{"F", "D", "C", "B", "A", "A++"};
    int grade = 99;
    
    if (grade < 0 || grade > 100) {
        std::cout << "invalid grade" << std::endl;
        return -1;
    }

    std::string letterGrade;
    if (grade < 60) {
        letterGrade = scores[0];
    } else if (grade <= 100) {
        letterGrade = scores[(grade - 50) / 10];
        int remainder = grade % 10;
        if (remainder <= 3) {
            letterGrade += '-';
        } else if (remainder >= 7) {
            letterGrade += '+';
        }
    }
    std::cout << letterGrade << std::endl;

    return 0;
}
