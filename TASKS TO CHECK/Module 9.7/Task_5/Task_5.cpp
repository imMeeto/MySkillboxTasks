#include <iostream>

int main() {
    std::cout << "*Программа-конвертер в Римские числа.*\n";

    int number;

    while (true) {
      std::cout << "[Пользователь]: Введите число (1-3999): ";
      std::cin >> number;

      if (number < 1 || number > 3999) {
          std::cout << "[Ошибка]: Число должно быть в диапазоне от 1 до 3999!\n";
          continue;
      } else {
        break;
      }
    }

    // Массивы для десятичных значений и соответствующих римских символов
    int decimalValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    std::string result = ""; // Результирующая строка

    for (int i = 0; i < 13; ++i) {
        while (number >= decimalValues[i]) {
            result += romanSymbols[i]; // Добавляем соответствующий символ
            number -= decimalValues[i];   // Вычитаем значение из числа
        }
    }

    std::cout << "[Программа]: Вывод: " << result << "\n";

    return 0;
}