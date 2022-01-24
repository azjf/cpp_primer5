#include <iostream>
#include <vector>

int main()
{
    const std::vector<std::string> scores{"F", "D", "C", "B", "A", "A++"};
    int grade = 99;
    
    std::string letterGrade;
    letterGrade = grade < 60 ? scores[0] :
        grade % 10 <= 3 ? scores[(grade - 50) / 10] + '-' :
        grade % 10 >= 7 ? scores[(grade - 50) / 10] + '+' :
        scores[(grade - 50) / 10];
    std::cout << letterGrade << std::endl;

    return 0;
}
