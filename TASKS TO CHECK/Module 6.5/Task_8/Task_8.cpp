#include <iostream>
// Бинарный поиск
int main() {
    int low = 0;
    int high = 63;
    std::string response;

    std::cout << "*** Угадай число от 0 до 63 ***" << "\n";
    std::cout << "Загадайте число и отвечайте на вопросы 'да' или 'нет'." << "\n";

    while (low <= high) {
        int mid = low + (high - low) / 2; // Находим середину диапазона
        std::cout << "Ваше число больше " << mid << "? (да/нет): ";
        
        while (true) {
            std::cin >> response;
            if (response == "да" || response == "нет") {
                break;
            } else {
                std::cout << "Пожалуйста, введите 'да' или 'нет': ";
            }
        }

        if (response == "да") {
            low = mid + 1; // Увеличиваем нижнюю границу
        } else {
            high = mid - 1; // Уменьшаем верхнюю границу
        }
    }

    std::cout << "Ваше число: " << low << "\n";
    std::cout << "*******************************" << "\n";
    
    return 0;
}
