#include <iostream>

int main () {
  std::cout << "--- Погашение долга ---" << "\n";
  std::cout << "Введите ваше имя: ";
  std::string name;
  std::cin >> name;

  int debt;
  std::cout << "Введите сумму долга: ";
  std::cin >> debt;

    int remainingDebt = debt;

    if (debt < 0) {
      std::cout << "Сумма долга не может быть отрицательной. Попробуйте снова.\n";
      return 1;
    }

  while (remainingDebt > 0) {
    int payment = 0;
    std::cout << "Введите сумму зачисления: ";
    std::cin >> payment;

    if (payment < 0) {
      std::cout << "Сумма зачисления не может быть отрицательной. Попробуйте снова.\n";
      continue;
    }

    remainingDebt -= payment; // Уменьшение оставшегося долга

    if (remainingDebt > 0) {
      std::cout << "Отлично, " << name << ", оставшаяся сумма долга: " << remainingDebt << "\n";
    } else {
      int excessPayment = -remainingDebt; // Избыточный платеж
      if (excessPayment > 0) {
        std::cout << "Долг погашен, " << name << "! Остаток на счету: " << excessPayment << "\n";
      } else {
        std::cout << "Долг погашен, " << name << "!" << "\n";
      }
    }
  }
}