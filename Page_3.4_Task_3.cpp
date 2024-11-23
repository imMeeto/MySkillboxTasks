#include <iostream>

int main()
{
    std::cout << "----Калькулятор высоты бамбука к середине третьего дня----" << "\n";
    std::cout << "Начальная высота бамбука:  ";
    int beginHeight;
    std::cin  >> beginHeight;

    std::cout << "Размер съедаемого гусеницами бамбука за одну ночь: ";
    int nightFade;
    std::cin  >> nightFade;

    std::cout << "Ежедневный рост бамбука: ";
    int dailyGrowth;
    std::cin  >> dailyGrowth;

    int thirdDayGrowth = beginHeight + ((dailyGrowth - nightFade) * 2 + (dailyGrowth / 2));

    std::cout << "----Рассчитываем...----" << "\n";
    std::cout << "Высота бамбука к середине третьего дня: " << thirdDayGrowth << "\n";
}