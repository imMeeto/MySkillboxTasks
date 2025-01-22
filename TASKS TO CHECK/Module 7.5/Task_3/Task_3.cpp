#include <iostream>

int main() {

    int x = 7; // Начальная позиция по X
    int y = 10; // Начальная позиция по Y
    int width = 20; 
    int height = 15; 
    char move;

    std::cout << "----------- Симулятор марсохода -----------" << "\n";
    std::cout << "Для движения, используйте W, A, S, D." << "\n";
    std::cout << "-------------------------------------------" << "\n";
    std::cout << "\n";

    while (true) {
        std::cout << "[Программа]: Марсоход находится на позиции " << x << ", " << y << ", введите команду:" << "\n";
        std::cout << "[Оператор]: ";
        std::cin >> move;

        if (move == 'W' || move == 'w') {
            if (y < height) y++; // На север
        } else if (move == 'S' || move == 's') {
            if (y > 1) y--; // На юг
        } else if (move == 'A' || move == 'a') {
            if (x > 1) x--; // На запад
        } else if (move == 'D' || move == 'd') {
            if (x < width) x++; // На восток
        } else {
            std::cout << "[Ошибка]: Неверная команда. Пожалуйста, используйте W, A, S, D." << "\n";
            continue;
        }
    }

    return 0;
}
