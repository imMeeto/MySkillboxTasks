#include <iostream>

int main() {
    std::cout << "Программа-тестер нового антибиотика компании «Терран Биотех»." << "\n";

    int N = 0; // количество бактерий
    int X = 0; // капли антибиотика

    std::cout << "Введите количество бактерий: ";
    std::cin >> N;

    std::cout << "Введите количество антибиотика: ";
    std::cin >> X;

    // Проверка на отрицательные значения
    if (N <= 0 || X <= 0) {
        std::cout << "Количество бактерий и антибиотика должны быть положительными!" << "\n";
        return 1;
    }

    for (int clockCounter = 0; X > 0; clockCounter++) {
        // Увеличение количества бактерий
        N *= 2;

        // Уменьшение количества бактерий из-за действия антибиотика
        X = 10 - clockCounter; // количество убитых бактерий
        if (X > 0) {
            N -= X;
        }

        std::cout << "После " << (clockCounter + 1) << " часа количество бактерий осталось: " << N << "\n";

        // Уменьшение количества капель антибиотика
        X--;

        if (N <= 0) {
            std::cout << "Все бактерии погибли!" << "\n";
            return 2;
        } else if (X <= 0) {
            std::cout << "Антибиотик закончился!" << "\n";
            return 3;
        }
    }

    return 0;
}
