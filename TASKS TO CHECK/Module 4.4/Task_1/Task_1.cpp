#include<iostream>

int main() {
  int firstNumber;
  int secondNumber;
  std::cout << "Ищем минимальное значение из двух чисел." << "\n";
<<<<<<< HEAD
<<<<<<< HEAD
  std::cout << "Введите первое число: ";
  std::cin  >> firstNumber;
  std::cout << "Введите второе число: ";
  std::cin  >> secondNumber;
  std::cout << "---Проверяем---" << "\n";
=======
  std::cout << "Введите первое число: " << "\n";
=======
  std::cout << "Введите первое число: ";
>>>>>>> dc3a12c (save)
  std::cin  >> firstNumber;
  std::cout << "Введите второе число: ";
  std::cin  >> secondNumber;
<<<<<<< HEAD
>>>>>>> 93d30b5 (save)
=======
  std::cout << "---Проверяем---" << "\n";
>>>>>>> dc3a12c (save)
  
  if(firstNumber > secondNumber) {
    std::cout << "Наименьшее число: " << secondNumber << "\n";
  } else if(secondNumber > firstNumber) {
    std::cout << "Наименьшее число: " << firstNumber << "\n";
  } else {
    std::cout << "Числа равны!";
  }
}