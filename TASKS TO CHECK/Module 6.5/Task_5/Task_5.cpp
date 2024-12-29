#include <iostream>

int main() {
  std::cout << "--- Счетчик чисел Фибоначчи ---" << "\n";
  int a = 0, b = 1, c = 0; // Первыe три числа Фибоначчи

  std::cout << "Введите номер последовательности: ";
  int N;
  std::cin >> N; 

  int i = 0; // Счетчик

  while (i < N) {
    a = b;
    b = c;
    c = a + b;
    i++;
  }
  
  std::cout << "Число в последовательности: " << c << " ";

return 0;
}