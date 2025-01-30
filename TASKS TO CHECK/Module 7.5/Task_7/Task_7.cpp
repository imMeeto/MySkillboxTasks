#include <iostream>

int main() {
    std::cout << "Программа-тестер нового антибиотика компании «Терран Биотех»." << "\n";

    int bacteria = 0; // количество бактерий
    int antibiotic = 0; // капли антибиотика

    std::cout << "Введите количество бактерий: ";
    std::cin >> bacteria;

    std::cout << "Введите количество антибиотика: ";
    std::cin >> antibiotic;

    if (bacteria <= 0 || antibiotic <= 0) {
        std::cout << "Количество бактерий и антибиотика должны быть положительными!" << "\n";
        return 1;
    }

    for (int clockCounter = 0; clockCounter < antibiotic && clockCounter < 10; clockCounter++) {
        bacteria *= 2; // Увеличение количества бактерий в 2 раза
        int killedBacteria = antibiotic * (10 - clockCounter); // Каждая капля антибиотика убивает 10, 9 и т.д. бактерий каждый час
        bacteria -= killedBacteria; // Уменьшение количества бактерий из-за действия антибиотика

        std::cout << "После " << (clockCounter + 1) << " часа количество бактерий: " << bacteria << "\n";

        if (bacteria <= 0) {
            std::cout << "Все бактерии погибли!" << "\n";
            return 2;
        }
    }

    std::cout << "Эксперимент окончен, выжило бактерий: " << bacteria << "\n";
    return 0;
}
