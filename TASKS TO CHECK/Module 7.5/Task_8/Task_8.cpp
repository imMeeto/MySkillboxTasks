#include <iostream>

int main() {
  std::cout << "Программа-Ёлочка." << "\n";

  int height;
  std::cout << "Введите высоту ёлочки: ";
  std::cin >> height;
  std::cout << "\n";

  if (height <= 0) {
    std::cout << "Высота ёлочки должна быть не меньше 1!" << "\n";
    return 1;
  }

  for (int i = 1; i <= height; i++) { // Цикл по высоте
    for (int j = 0; j < height - i; j++) { // Цикл пробелов
      std::cout << " ";
    }
    for (int k = 0; k < i * 2 - 1; k++) { // Цикл решеток
      std::cout << "#";
    }
    std::cout << "\n";
  }
  
  return 0;
}