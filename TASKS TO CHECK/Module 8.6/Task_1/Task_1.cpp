#include <iostream>
#include <cmath>

int main() {
  std::cout << "Симулятор космических полётов." << "\n";

  float weight, thrust, seconds = 0;

  std::cout << "Введите вес звездолета (в килограммах): ";
  std::cin >> weight;
  if (weight <= 0) {
      std::cout << "Ошибка: вес должен быть положительным." << "\n";
      return 1;
  }

  std::cout << "Введите тягу двигателя (в ньютонах): ";
  std::cin >> thrust;
  if (thrust <= 0) {
      std::cout << "Ошибка: тяга должна быть положительной." << "\n";
      return 1;
  }

  std::cout << "Введите время работы двигателя (в секундах): ";
  std::cin >> seconds;
  if (seconds <= 0) {
      std::cout << "Ошибка: время должно быть положительным." << "\n";
      return 1;
  }

  float acceleration = thrust / weight;
  float distance = (acceleration * std::pow(seconds, 2)) / 2;

  std::cout << "Звездолет оказался на расстоянии " << distance << " метров через " << seconds << " секунд." << "\n";
  return 0;
}
