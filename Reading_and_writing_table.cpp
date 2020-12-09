#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

int main() {
    std::ifstream input("input.txt");
    int x = 0;
    int y = 0;
    input >> x >> y;
    std::vector<std::vector<int>> mat(x, std::vector<int>(y, 0));
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            input >> mat[i][j];
            input.ignore(1);
        }
    }
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            if (j != y - 1) {
                std::cout << std::setw(10) << mat[i][j] << " ";
            } else {
                std::cout << std::setw(10) << mat[i][j];
            }
        }
        std::cout << '\n';
    }
    return 0;
}