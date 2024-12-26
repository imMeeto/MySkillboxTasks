#include <iostream>

int main() {
	std::cout << "Программа: Часы с кукушкой." << "\n";
	std::cout << "Введите, который час: ";
	int hour;
	std::cin >> hour;

  while (true) {
      if (hour < 0 || hour > 23) {
        std::cout << "Ошибка! Введите число от 0 до 23!" << "\n"; 
        std::cout << "Введите, который час: ";
        std::cin >> hour;
      } else {
        break;
      }
  }

	int count = 0;

  if (hour == 0) {
      while (count < 24) {
        std::cout << "Ку-ку!" << "\n";
        count++;
      }
  } else {
      while (count != hour) {
        std::cout << "Ку-ку!" << "\n";
        count++;
      }
  }
}