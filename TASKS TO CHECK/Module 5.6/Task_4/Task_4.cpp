#include <iostream>

int main() {
  std::cout << "--- Банкомат ---" << "\n";
  std::cout << "Купюры: 100, 200, 500, 1000, 2000 и 5000 рублей." << "\n";

  std::cout << "Введите сумму, которую необходимо снять: ";
  int amountOfMoney;
  std::cin >> amountOfMoney;

    while (true) {
      if (amountOfMoney <= 0) {
        std::cout << "Ошибка: вы должны ввести положительную сумму!" << "\n";
        std::cout << "Введите сумму, которую необходимо снять: ";
        std::cin >> amountOfMoney;
      } else if (amountOfMoney > 150000) {
        std::cout << "Ошибка: максимальная сумма для снятия составляет 150000 рублей!" << "\n";
        std::cout << "Введите сумму, которую необходимо снять: ";
        std::cin >> amountOfMoney;
      } else if (amountOfMoney % 100 != 0) {
        std::cout << "Ошибка: сумма должна делиться на 100." << "\n";
        std::cout << "Введите сумму, которую необходимо снять: ";
        std::cin >> amountOfMoney;
      } else {
        break;
      }
    }

  int count5000 = 0, count2000 = 0, count1000 = 0, count500 = 0, count200 = 0, count100 = 0;

    if (amountOfMoney >= 5000) {
        count5000 = amountOfMoney / 5000;
        amountOfMoney %= 5000;
    }
    if (amountOfMoney >= 2000) {
        count2000 = amountOfMoney / 2000;
        amountOfMoney %= 2000;
    }
    if (amountOfMoney >= 1000) {
        count1000 = amountOfMoney / 1000;
        amountOfMoney %= 1000;
    }
    if (amountOfMoney >= 500) {
        count500 = amountOfMoney / 500;
        amountOfMoney %= 500;
    }
    if (amountOfMoney >= 200) {
        count200 = amountOfMoney / 200;
        amountOfMoney %= 200;
    }
    if (amountOfMoney >= 100) {
        count100 = amountOfMoney / 100;
        amountOfMoney %= 100;
    }

  std::cout << "----------------" << "\n";
  std::cout << "Выдано:" << "\n";

    if (count5000 > 0) std::cout << "- купюр по 5000: " << count5000 << "\n";
    if (count2000 > 0) std::cout << "- купюр по 2000: " << count2000 << "\n";
    if (count1000 > 0) std::cout << "- купюр по 1000: " << count1000 << "\n";
    if (count500 > 0) std::cout << "- купюр по 500: " << count500 << "\n";
    if (count200 > 0) std::cout << "- купюр по 200: " << count200 << "\n";
    if (count100 > 0) std::cout << "- купюр по 100: " << count100 << "\n";

  return 0;
}
