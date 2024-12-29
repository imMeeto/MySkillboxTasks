#include <iostream>

int main () {
    std::cout << "--- Определяем, счастливый билетик или нет ---" << "\n";
    std::cout << "Введите номер билета (6-ти значное число): ";
    int digits;
    std::cin >> digits;

    int sumFirstHalf = 0;
    int sumSecondHalf = 0;
    int count = 0;

    while (digits > 0) {
      int one_digit = digits % 10; // Получаем младший разряд
      digits /= 10; // Убираем

        if (count < 3) {
            sumFirstHalf += one_digit; // Сумма первых трех цифр
        } else {
            sumSecondHalf += one_digit; // Сумма последних трех цифр
        }
      count++;
    }

    if (sumFirstHalf == sumSecondHalf) {
        std::cout << "Билет счастливый!" << "\n";
    } else {
        std::cout << "Повезёт в следующий раз!" << "\n";
    }

    return 0;
}