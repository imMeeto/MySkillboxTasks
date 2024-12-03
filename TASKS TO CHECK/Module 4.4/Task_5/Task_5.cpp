#include <iostream>

int main() {
  std::cout << "Проверяем, делится ли одно число на другое без остатка." << "\n";
  std::cout << "Введите первое число: ";
  int firstNumber;
  std::cin  >> firstNumber;
  std::cout << "Введите второе число: ";
  int secondNumber;
  std::cin  >> secondNumber;
  std::cout << "---Проверяем---" << "\n";
  
    if(firstNumber % secondNumber == 0) {
    std::cout << "Число " << firstNumber << " делится на " << secondNumber << " без остатка!" << "\n";
    } else {
    std::cout << "Число " << firstNumber << " не делится на " << secondNumber << " без остатка!" << "\n";
    }
}