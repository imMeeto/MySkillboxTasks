#include <iostream>

int main() {
std::cout << "\n";

    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 50; col++) {
            if (row == 10) {
                if (col == 25) {
                    std::cout << "+"; // Пересечение осей
                } else if (col == 49) {
                    std::cout << ">"; // Стрелка вправо
                } else {
                    std::cout << "-"; // Горизонтальная ось
                }
            } else if (col == 25) {
                if (row == 0) {
                    std::cout << "^"; // Стрелка вверх
                } else {
                    std::cout << "|"; // Вертикальная ось
                }
            } else {
                std::cout << " "; // Пустое пространство
            }
        }
        std::cout << "\n"; // Переход на новую строку
    }

    std::cout << "\n";
    
    return 0;
}
