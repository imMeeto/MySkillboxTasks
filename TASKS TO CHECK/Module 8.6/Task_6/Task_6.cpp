#include <iostream>

int main() {
    std::cout << "Симулятор маятника.";

    double initialAmplitude, finalAmplitude;
    int swings = 0;

    std::cout << "Введите начальную амплитуду (в см): ";
    std::cin >> initialAmplitude;
    std::cout << "Введите конечную амплитуду (в см): ";
    std::cin >> finalAmplitude;

    if (initialAmplitude <= finalAmplitude || initialAmplitude <= 0 || finalAmplitude < 0) {
        std::cout << "Начальная амплитуда должна быть больше конечной и больше нуля!" << "\n";
        return 1;
    }

    // Цикл затухания
    while (initialAmplitude > finalAmplitude) {
        initialAmplitude *= 0.916; // Уменьшение на 8.4%
        swings++;
    }

    std::cout << "Маятник качнется " << swings << " раз перед остановкой." << "\n";

    return 0;
}
