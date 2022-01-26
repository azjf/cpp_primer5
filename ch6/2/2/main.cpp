#include <iostream>

void print(int (*matrix)[10], int rowSize)
{
    for (int i = 0; i != rowSize; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int imatrix[2][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}
    };
    print(imatrix, 2);
    return 0;
}
