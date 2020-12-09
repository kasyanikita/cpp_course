#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream input("input.txt");
    std::cout << std::fixed << std::setprecision(3);
    if (input) {
        double number;
        while (input >> number) {
            std::cout << number << '\n';
        }
    } else {
        std::cout << "ERROR" << '\n';
    }
    return 0;
}