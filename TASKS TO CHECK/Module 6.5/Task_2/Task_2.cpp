#include <iostream>

int main() {
    std::cout << "--- Калькулятор цифр в вводимом числе. ---" << "\n";
    int number; 
    std::cout << "Введите число: ";
    std::cin >> number;

    if (number == 0) {
        std::cout << "Цифр в числе: 1\n";
        return 0;
    }

    if (number < 0) {
        number = -number; // Приводим number к положительному
    }

    int count = 0;
    while (number > 0) {
        number /= 10; 
        count++;
    }

    std::cout << "Цифр в числе: " << count << "\n";

    return 0;
}