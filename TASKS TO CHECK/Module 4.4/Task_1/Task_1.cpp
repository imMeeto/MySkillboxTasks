#include<iostream>

int main() {
  int firstNumber;
  int secondNumber;
  std::cout << "Ищем минимальное значение из двух чисел." << "\n";
<<<<<<< HEAD
  std::cout << "Введите первое число: ";
  std::cin  >> firstNumber;
  std::cout << "Введите второе число: ";
  std::cin  >> secondNumber;
  std::cout << "---Проверяем---" << "\n";
=======
  std::cout << "Введите первое число: " << "\n";
  std::cin  >> firstNumber;
  std::cout << "Введите второе число: " << "\n";
  std::cin  >> secondNumber;
>>>>>>> 93d30b5 (save)
  
  if(firstNumber > secondNumber) {
    std::cout << "Наименьшее число: " << secondNumber << "\n";
  } else if(secondNumber > firstNumber) {
    std::cout << "Наименьшее число: " << firstNumber << "\n";
  } else {
    std::cout << "Числа равны!";
  }
}