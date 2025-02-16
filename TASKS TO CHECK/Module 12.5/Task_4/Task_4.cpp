#include <iostream>

int main() {
  std::cout << "*Find a duplicate number.*\n";

  int numbers[15];
  std::cout << "Input 15 consecutive numbers: \n";
  for (int i = 0; i < 15; ++i) {
    std::cin >> numbers[i];
  }

  // Находим минимальный элемент
  int minElement = numbers[0];
  for (int i = 1; i < 15; ++i) {
      if (numbers[i] < minElement) {
          minElement = numbers[i];
      }
  }

  // Вычисляем сумму всех чисел в массиве
  int sumArray = 0;
  for (int i = 0; i < 15; ++i) {
      sumArray += numbers[i];
  }

  // Вычисляем сумму последовательности без повторяющегося числа
  // Последовательность состоит из (n = 14) чисел
  // Формула арифм. прогрессии: S = n/2 * (первый элемент + последний элемент)
  int sumProgression = 14 * minElement + 91;

  int duplicate = sumArray - sumProgression;

  std::cout << "Duplicate number: " << duplicate << "\n";

  return 0;
}