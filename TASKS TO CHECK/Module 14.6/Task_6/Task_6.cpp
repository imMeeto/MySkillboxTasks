#include <iostream>
#include <iomanip>

int main() {
    const int size = 5;
    int digits[size][size];
    int number = 0;

    for (int i = 0; i < size; ++i) {
        int multiplier = (i % 2 == 0) ? 1 : -1;
        int start = (multiplier == 1) ? 0 : size - 1;
        int end = (multiplier == 1) ? size : -1;

        for (int j = start; j != end; j += multiplier) {
            digits[i][j] = number++;
        }
    }

    // Вывод массива на экран
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << digits[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}