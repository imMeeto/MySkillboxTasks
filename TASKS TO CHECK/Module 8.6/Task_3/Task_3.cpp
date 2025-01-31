#include <iostream>
#include <cmath> // для функции std::floor

int main() {
    std::cout << "Производство игровых деревянных кубиков 5x5x5 см." << "\n";

    const int CUBE_X = 5, CUBE_Y = 5, CUBE_Z = 5;
    const int CUBE_FULL = CUBE_X * CUBE_Y * CUBE_Z; // основной кубик 5*5*5 см

    float woodBarX, woodBarY, woodBarZ;
    std::cout << "Введите размеры бруска: " << "\n";
    std::cout << "X: ";
    std::cin >> woodBarX;
    std::cout << "Y: ";
    std::cin >> woodBarY;
    std::cout << "Z: ";
    std::cin >> woodBarZ;

    // Проверка на минимальный размер бруска
    if (woodBarX < 5 || woodBarY < 5 || woodBarZ < 5) {
        std::cout << "Размеры бруска должны быть не менее 5 см." << "\n";
        return 1;
    }

    float woodBarFull = woodBarX * woodBarY * woodBarZ;
    int makedCubes = static_cast<int>(woodBarFull / CUBE_FULL); // округление вниз до целого числа

    std::cout << "Из этого бруска можно изготовить: " << makedCubes << " кубиков." << "\n";

    // Проверка на то, сколько готовых кубиков уместится в набор (box), минимальный размер набора — 2x2x2 = 8 кубиков.
    int box = 2;
    int willBoxes = 0;

    while (willBoxes <= makedCubes) {
        willBoxes = box * box * box;
        box++;
    }

    // Вывод количества кубиков в наборе
    int cubesInSet = (box - 2) * (box - 2) * (box - 2); // -2 для учета одного кубика
    std::cout << "Из них можно составить набор из " << cubesInSet << " кубиков." << "\n";

    return 0;
}
