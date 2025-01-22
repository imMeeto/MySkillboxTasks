#include <iostream>

int main() {

    std::cout << "----- Программа нарисует рамку по вашим параметрам. -----" << "\n";

    int width, height;
    std::cout << "Введите ширину и высоту рамки: ";
    std::cin >> width >> height;
    std::cout << "\n";

    //Начало отрисовки
    std::cout << "|";

    for (int j = 0; j < width - 2; j++) {
        std::cout << "-";
    }

    std::cout << "|\n"; // Первая строка

    for (int i = 0; i < height - 2; i++) {
        std::cout << "|"; // Левая граница
        for (int j = 0; j < width - 2; j++) {
        std::cout << " "; // Пробелы между границами
        }
        std::cout << "|\n"; // Правая граница
    }

    std::cout << "|";

    for (int j = 0; j < width - 2; j++) {
    std::cout << "-";
    }

    std::cout << "|\n"; // Последняя строка
    std::cout << "\n";

    return 0;
}
