#include <iostream>

int main() {

    int water, milk;
    int addWater;
    int addMilk;
    int americanoCount = 0, latteCount = 0;

    std::cout << "*** Кофемашина ***" << "\n";
    std::cout << "Пожалуйста, добавьте ингридиенты." << "\n";
    std::cout << "\n";
    std::cout << "Введите количество воды в мл: ";
    std::cin >> water;
    std::cout << "Введите количество молока в мл: ";
    std::cin >> milk;

    while (true) {
        int choice;
        std::cout << "\n";
        std::cout << "Выберите напиток (1 — американо, 2 — латте): ";
        std::cin >> choice;

        if (choice == 1) { // американо
            if (water >= 300) {
                water -= 300;
                americanoCount++;
                std::cout << "Ваш напиток готов." << "\n";
            } else {
                std::cout << "Не хватает воды." << "\n";
                std::cout << "Введите количество воды в мл: ";
                std::cin >> addWater;
                water += addWater;
            }
        } else if (choice == 2) { // латте
            if (water >= 30 && milk >= 270) {
                water -= 30;
                milk -= 270;
                latteCount++;
                std::cout << "Ваш напиток готов." << "\n";
            } else if (water < 30) {
                std::cout << "Не хватает воды." << "\n";
                std::cout << "Введите количество воды в мл: ";
                std::cin >> addWater;
                water += addWater;
            } else {
                std::cout << "Не хватает молока." << "\n";
                std::cout << "Введите количество молока в мл: ";
                std::cin >> addMilk;
                milk += addMilk;
            }
        } else {
            std::cout << "Неверный выбор." << "\n";
        }

        // Вывод отчета после каждой покупки
        std::cout << "\n";
        std::cout << "***Отчет***" << "\n";
        std::cout << "Вода: " << water << " мл" << "\n";
        std::cout << "Молоко: " << milk << " мл" << "\n";
        std::cout << "Кружек американо приготовлено: " << americanoCount << "\n";
        std::cout << "Кружек латте приготовлено: " << latteCount << "\n";

        // Проверка на остаток ингредиентов
        if (water < 300 && (water < 30 || milk < 270)) {
            std::cout << "\n";
            std::cout << "Ингредиенты закончились, нельзя приготовить ни один из напитков. Пожалуйста, добавьте ингредиенты." << "\n";
            break;
        }
    }
}