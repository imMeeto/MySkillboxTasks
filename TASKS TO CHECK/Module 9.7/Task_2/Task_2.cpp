#include <iostream>
#include <string>

bool isValidRealNumber(const std::string& str) {
    if (str.empty()) {
        return false; // Пустая строка некорректна
    }

    int length = str.length();
    bool hasDigit = false; // Флаг наличия хотя бы одной цифры
    bool hasDot = false;   // Флаг наличия точки

    for (int i = 0; i < length; ++i) {
        char ch = str[i];

        if (i == 0) {
            // Проверка первого символа
            if (ch == '-' || ch == '.' || (ch >= '0' && ch <= '9')) {
                if (ch >= '0' && ch <= '9') {
                    hasDigit = true;
                }
                if (ch == '.') {
                    hasDot = true;
                }
            } else {
                return false; // Недопустимый первый символ
            }
        } else {
            // Проверка остальных символов
            if (ch >= '0' && ch <= '9') {
                hasDigit = true;
            } else if (ch == '.') {
                if (hasDot) {
                    return false; // Точка уже была
                }
                hasDot = true;
            } else {
                return false; // Недопустимый символ
            }
        }
    }

    // Хотя бы одна цифра должна быть
    return hasDigit;
}

int main() {
    std::string input;
    std::cout << "Введите строку: ";
    std::cin >> input;

    if (isValidRealNumber(input)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}