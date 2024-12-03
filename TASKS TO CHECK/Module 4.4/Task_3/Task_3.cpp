#include <iostream>

int main() {
  int number;
  std::cout << "Проверяем число на четность." << "\n";
  std::cout << "Введите число: ";
  std::cin  >> number;
  std::cout << "---Проверяем---" << "\n";
  if(number % 2 == 0) {
    std::cout << "Число четное!" << "\n";
  } else {
    std::cout << "Число нечетное!" << "\n";
  }
}