#include <iostream>
#include <cmath>

int main() {
    std::cout << "Производство игровых деревянных кубиков 5x5x5 см. из бруска.\n";

    float X, Y, Z;
    std::cout << "Введите размеры бруска (X, Y, Z):\n";
    std::cout << "X: ";
    std::cin >> X;
    std::cout << "Y: ";
    std::cin >> Y;
    std::cout << "Z: ";
    std::cin >> Z;

    if (X < 5 || Y < 5 || Z < 5) {
        std::cout << "Размеры бруска должны быть не менее 5 см.\n";
        return 1;
    }

    // Отбрасываем дробную часть и округляем вниз. Делим размеры бруска на 5, чтобы получить количество кубиков по каждому размеру
    int cubes = static_cast<int>(X / 5) * static_cast<int>(Y / 5) * static_cast<int>(Z / 5);
    std::cout << "Из этого бруска можно изготовить " << cubes << " кубиков." << "\n";

    // Вычисляем кубический корень из общего количества кубиков
    int maxSet = std::cbrt(cubes);
    // Проверяем, можем ли мы собрать набор
    if (maxSet * maxSet * maxSet <= cubes) {
        std::cout << "Из них можно составить набор из " << maxSet * maxSet * maxSet << " кубиков.\n";
    } else {
        std::cout << "Набор собрать нельзя.\n";
    }
    
    return 0;
}
