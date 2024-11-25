#include <iostream>

int main() {
  float number;
  float module;
  std::cout << "---Калькулятор модуля числа.---" << "\n";
  std::cout << "Введите число: " ;
  std::cin >> number;

  if (number < 0)
  {
    module =- number;
    std::cout << "Модуль числа " << number << " равен: " << module << "\n";
  }
  
  if (number > 0)
  {
    module = number;
    std::cout << "Модуль числа " << number << " равен: " << module << "\n";
  }

    // конечно, проще это сделать с помощью функции abs()

}