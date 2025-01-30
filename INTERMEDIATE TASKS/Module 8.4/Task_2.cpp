#include <iostream>
#include <cmath>

int main() {
    double angleDegrees;
    std::cout << "Введите угол тангажа в градусах: ";
    std::cin >> angleDegrees;

    // Преобразование угла в радианы
    double angleRadians = angleDegrees * M_PI / 180.0;

    // Проверка угла
    std::cout << ((angleRadians >= -0.28 && angleRadians <= 0.28) ? "Угол безопасен." : "Угол небезопасен!") << std::endl;
    std::cout << angleRadians;

    return 0;
}
