#include <iostream>

int main() {
  std::cout << "Определените уровня персонажа." << "\n";
  std::cout << "Введите количество опыта: ";
  int exp;
  std::cin  >> exp;
  std::cout << "---Проверяем---" << "\n";
    if(exp < 1000) {
      std::cout << "Ваш уровень: 1" << "\n";
    } else if(exp >= 1000 && exp < 2500) {
      std::cout << "Ваш уровень: 2" << "\n";
    } else if(exp >= 2500 && exp < 5000) {
      std::cout << "Ваш уровень: 3" << "\n";
    } else if(exp >= 5000) {
      std::cout << "Ваш уровень: 4. Вы достигли максимального уровня!" << "\n";
    }
  }