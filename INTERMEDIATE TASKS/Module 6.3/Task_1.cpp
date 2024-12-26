#include <iostream>

int main() {
    std::cout << "Введите ваш пин-код: ";
    int pinCode; 
    std::cin >> pinCode;

    int sum = 0;
    while (pinCode > 0) {
        sum += pinCode % 10; // Добавляем последнюю цифру к сумме
        pinCode /= 10; // Убираем последнюю цифру
    }

    if (sum == 42) {
        std::cout << "Пин-код корректный!";
    } else {
        std::cout << "Пин-код некорректный!";
    }

    return 0;
}