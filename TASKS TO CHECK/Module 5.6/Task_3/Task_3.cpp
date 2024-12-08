#include <iostream>

int main() 
{
  std::cout << "Проверьте, является ли выходным день в мае." << "\n";

  int startDayOfWeek;
  std::cout << "Введите номер дня, с которого начинается май (1-пн; 7-вс): ";
  std::cin >> startDayOfWeek;

        while (true) {
        if (startDayOfWeek < 1 || startDayOfWeek > 7) {
            std::cout << "Вы должны ввести число от 1 до 7!" << "\n";
            std::cout << "Введите номер дня, с которого начинается май (1-пн; 7-вс): "; 
            std::cin >> startDayOfWeek; 
        } else {
            break; 
        }
    }

  int dayOfMounth;
  std::cout << "Введите день месяца: ";
  std::cin >> dayOfMounth;

      while (true) {
          if (dayOfMounth < 1 || dayOfMounth > 31) {
              std::cout << "Вы должны ввести число от 1 до 31." << "\n";
              std::cout << "Введите день месяца: "; 
              std::cin >> dayOfMounth; 
          } else {
              break; 
          }
      }
  
  std::cout << "----------------------------" << "\n";

      std::string nameOfDay[] = {
      "Понедельник",
      "Вторник",
      "Среда",
      "Четверг",
      "Пятница",
      "Суббота",
      "Воскресенье"
    };

  // Определяем день недели для введённого дня
  int currentDay = (startDayOfWeek + (dayOfMounth - 1)) % 7;

  if (currentDay == 0) { //Присваиваем 7, если результат равен 0 для использования в массиве
    currentDay = 7;
  }
  
    // Проверяем, является ли день выходным
    if (currentDay == 6 || currentDay == 7 ||      // сб или вс
        (dayOfMounth >= 1 && dayOfMounth <= 5) ||  // 1-5 мая
        (dayOfMounth >= 8 && dayOfMounth <= 10)) { // 8-10 мая
        std::cout << nameOfDay[currentDay - 1] << " является выходным в мае." << "\n";
    } else {
        std::cout << nameOfDay[currentDay - 1] << " не является выходным в мае." << "\n"; 
    }

  return 0;
}