#include <iostream>

int main() {
  std::cout << "--- Проверьте возраст покупателя ---" << "\n";

  int day;
  int month;
  int year;
  std::cout << "Введите сегодняшнюю дату." << "\n";
  std::cout << "День: ";
  std::cin >> day;
  std::cout << "Месяц: ";
  std::cin >> month;
  std::cout << "Год: ";
  std::cin >> year;

    while (true) {
      if ((day < 1 || day > 31) ||
          (month < 1 || month > 12) ||
          (year < 1900 || year > 2024)) {
            std::cout << "Некорректная дата. Пожалуйста, введите корректную дату." << "\n";
              std::cout << "День: ";
              std::cin >> day;
              std::cout << "Месяц: ";
              std::cin >> month;
              std::cout << "Год: ";
              std::cin >> year;
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

  int age = year - birthYear;

    // Проверка, был ли день рождения в этом году
    if (month < birthMonth || (month == birthMonth && day < birthDay)) {
        age--;
    }

    std::cout << "Возраст покупателя: " << age << " лет." << "\n";

  return 0;
}