#include <iostream>

int main() {
    int height;

    // Запрос высоты ёлочки
    std::cout << "Введите высоту ёлочки: ";
    std::cin >> height;

    // Проверка ввода
    if (height <= 0) {
        std::cout << "Высота должна быть положительным целым числом." << "\n";
        return 1;
    }

    // Формирование ёлочки
    for (int i = 1; i <= height; ++i) {
        // Вывод пробелов
        for (int j = 0; j < height - i; ++j) {
            std::cout << " ";
        }
        // Вывод символов #
        for (int k = 0; k < 2 * i - 1; ++k) {
            std::cout << "#";
        }
        std::cout << "\n";
    }

    return 0;
}
