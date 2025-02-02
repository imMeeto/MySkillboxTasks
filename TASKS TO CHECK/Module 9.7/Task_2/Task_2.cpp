#include <iostream>

int main() {
    std::cout << "Check if the float number is written correctly.\n";

    std::string input;
    std::cout << "Input float number: ";
    std::cin >> input;

    if (input.empty()) {
        std::cout << "No!\n";
        return 0;
    }

    int dotCount = 0; // Счетчик точек
    bool hasDigit = false; // Флаг наличия цифры

    // Проверка первого символа
    if (input[0] == '-' || input[0] == '.' || (input[0] >= '0' && input[0] <= '9')) {
        if (input[0] >= '0' && input[0] <= '9') {
            hasDigit = true;
        }
    } else {
        std::cout << "No!\n";
        return 0;
    }

    // Проверка остальных символов
    for (int i = 1; i < input.length(); ++i) {
        if (input[i] >= '0' && input[i] <= '9') {
            hasDigit = true; // Найдена цифра
        } else if (input[i] == '.') {
            dotCount++; // Если нашли точку, то увеличиваем счетчик
            if (dotCount > 1) {
                std::cout << "No!\n";
                return 0;
            }
        } else {
            std::cout << "No!\n";
            return 0;
        }
    }

    if (hasDigit) {
        std::cout << "Yes!\n";
    } else {
        std::cout << "No!\n";
    }

    return 0;
}
