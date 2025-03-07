#include <iostream>

int main() {
    std::cout << "[Программа]: Убей орка огненным шаром!" << "\n";

    float health, magicResistance;

    std::cout << "[Игрок]: Количество здоровья орка (0-1): ";
    std::cin >> health;
    std::cout << "[Игрок]: Количество сопротивления магии (0-1): ";
    std::cin >> magicResistance;

    if (health < 0 || health > 1 || magicResistance < 0 || magicResistance > 1) {
        std::cout << "[Ошибка]: значения должны быть в диапазоне от 0 до 1." << "\n";
        return 1;
    }

    float damage;
    while (health > 0) {
        std::cout << "[Игрок]: Мощность огненного шара (0-1): ";
        std::cin >> damage;

        if (damage < 0 || damage > 1) {
            std::cout << "[Ошибка]: Мощность должна быть в диапазоне от 0 до 1." << "\n";
            continue;
        }

        // Расчет урона
        float actualDamage = damage * (1 - magicResistance);
        health -= actualDamage;

        std::cout << "[Программа]: Наносим урон огненным шаром!" << "\n";
        std::cout << "[Программа]: Урон от удара: " << actualDamage << "\n";

        if (health < 0) {
            health = 0;
        }

        std::cout << "[Программа]: Оставшееся здоровье орка: " << health << "\n";

        if (health <= 0) {
            std::cout << "[Программа]: Орк погиб!" << "\n";
        }
    }
}
