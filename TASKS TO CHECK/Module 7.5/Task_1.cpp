#include <iostream>

int main() {
    int totalBuckwheat = 100;
    int monthlyConsumption = 4;
    int monthInput;

    std::cout << "Всего гречки было на начало подсчёта: " << totalBuckwheat << " кг" << "\n";
    std::cout << "Введите номер месяца: ";
    std::cin >> monthInput;

    for (int month = 1; month <= monthInput; month++) {
        totalBuckwheat -= monthlyConsumption;
        if (totalBuckwheat > 0) {
            std::cout << "После " << month << " месяца у вас в запасе останется " << totalBuckwheat << " кг гречки" << "\n";
        } else {
            std::cout << "После " << month << " месяца гречка закончится" << "\n";
            break;
        }
    }

    return 0;
}