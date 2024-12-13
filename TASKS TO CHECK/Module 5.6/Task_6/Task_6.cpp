#include <iostream>

int main() {
  std::cout << "--- Проверьте можно ли продавать алкоголь покупателю ---" << "\n";

  int currentDay;
  int currentMonth;
  int currentYear;
  std::cout << "Введите сегодняшнюю дату." << "\n";
  std::cout << "День: ";
  std::cin >> currentDay;
  std::cout << "Месяц: ";
  std::cin >> currentMonth;
  std::cout << "Год: ";
  std::cin >> currentYear;

    while (true) {
      if ((currentDay < 1 || currentDay > 31) ||
          (currentMonth < 1 || currentMonth > 12) ||
          (currentYear < 1900 || currentYear > 2024)) {
            std::cout << "Некорректная дата. Пожалуйста, введите корректную дату." << "\n";
              std::cout << "День: ";
              std::cin >> currentDay;
              std::cout << "Месяц: ";
              std::cin >> currentMonth;
              std::cout << "Год: ";
              std::cin >> currentYear;
      } else {
      break;
      }
    }

  int birthDay;
  int birthMonth;
  int birthYear;
  std::cout << "Введите дату рождения покупателя: " << "\n";
  std::cout << "День: ";
  std::cin >> birthDay;
  std::cout << "Месяц: ";
  std::cin >> birthMonth;
  std::cout << "Год: ";
  std::cin >> birthYear;

      while (true) {
        if ((birthDay < 1 || birthDay > 31) ||
            (birthMonth < 1 || birthMonth > 12) ||
            (birthYear < 1900 || birthYear > 2024)) {
              std::cout << "Некорректная дата. Пожалуйста, введите корректную дату." << "\n";
                std::cout << "День: ";
                std::cin >> birthYear;
                std::cout << "Месяц: ";
                std::cin >> birthYear;
                std::cout << "Год: ";
                std::cin >> birthYear;
        } else {
        break;
        }
      }

  std::cout << "-------------------------" << "\n";

if (currentYear - birthYear < 18) {
  std::cout << "Продавать алкоголь этому покупателю нельзя!" << "\n";
} else if (currentYear - birthYear > 18) {
  std::cout << "Продавать алкоголь этому покупателю можно!" << "\n";
} else if (currentMonth > birthMonth || (currentMonth == birthMonth && currentDay > birthDay)) {
  std::cout << "Продавать алкоголь этому покупателю можно!" << "\n";
} else {
  std::cout << "Продавать алкоголь этому покупателю нельзя!" << "\n";
}

  return 0;
}