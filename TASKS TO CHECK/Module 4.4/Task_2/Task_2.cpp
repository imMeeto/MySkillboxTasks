#include <iostream>

int main() {
  int firstNumber;
  int secondNumber;
  std::cout << "Проверяем число которое вы подсчитали в уме!" << "\n";
  std::cout << "Введите первое число: ";
  std::cin  >> firstNumber;
  std::cout << "Введите второе число: ";
  std::cin  >> secondNumber;
  std::cout << "Введите их сумму: ";
  int sum;
  std::cin  >> sum;
  std::cout << "---Проверяем---" << "\n";
  int result = firstNumber + secondNumber;
if(sum == result) {
    std::cout << "Верно!" << "\n";
  } else {
    std::cout << "Ошибка! Верный результат: " << result << "\n";
  }
}