#include <iostream>

int main() {
  std::cout << "--- Определите количество лет до достижения нужной суммы на вкладе ---" << "\n";
  std::cout << "Введите размер вклада: ";
  int deposit;
  std::cin >> deposit;

  std::cout << "Введите процентную ставку: ";
  int interestRate;
  std::cin >> interestRate;

  std::cout << "Введите желаемую сумму: ";
  int needSum;
  std::cin >> needSum;

  int years = 0;

  while (deposit < needSum) {
    deposit += deposit * interestRate / 100; // Начисление процентов
    years++;
    }

    std::cout << "Придется подождать " << years << " лет, чтобы достигнуть сумму " << needSum << "." << "\n";

    return 0;
}