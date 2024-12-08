#include <iostream>

int main() 
{
  std::cout << "Проверьте, является ли выходным день в мае." << "\n";

  int day;
  std::cout << "Введите день: ";
  std::cin >> day;

    while (true) {
        if (day < 1 || day > 31) {
            std::cout << "Введите число от 1 до 31." << "\n";
            std::cout << "Введите день: "; 
            std::cin >> day; 
        } else {
            break; 
        }
    }
  
  std::cout << "------------------------------" << "\n";

    if (day == 6 || day == 7 || day == 13 || day == 14 || day == 20 || day == 21 || day == 27 || day == 28) {
          std::cout << "День является выходным." << "\n";
      } else if (day >= 1 && day <= 5 || day >= 8 && day <= 10) {
          std::cout << "День является выходным." << "\n";
      } else {
          std::cout << "День не является выходным." << "\n"; 
    }

  return 0;
}