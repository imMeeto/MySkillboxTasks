#include <iostream>

int main() {
  int people;
  int barbers;
  std::cout << "---Рассчет необходимого количества барберов.---" << "\n";
  std::cout << "Введите количество человек проживающих в городе: " ;
  std::cin >> people;
  int men = people / 2;
  std::cout << "По статистике, в городе проживает 50% мужчин, поэтому мужчин: " << men << "\n";

  std::cout << "Введите количество уже работающих барберов: " ;
  std::cin >> barbers;
  std::cout << "Производим рассчет..." << "\n";
  std::cout << "------------------------------------------------" << "\n";

  int barbersPerMonth = men / 8;
  int barbersPerDay;
  int everyDayNeededBarbers = barbersPerMonth / 30;
  int needBarbers = barbersPerMonth - barbers;
  barbersPerDay = needBarbers / 30;
  int deleteBarbers = barbers - barbersPerMonth;

  if(barbers < barbersPerMonth) {
  std::cout << "Так как за месяц требуется подстричь " << men << " мужчин, ежемесячно должно работать " << barbersPerMonth << " барберов ";
  std::cout << "или " << everyDayNeededBarbers << " ежедневно." << "\n";
  std::cout << "Так как у вас уже работает " << barbers << " барберов, необходимо нанять " << needBarbers << " барберов для ежемесячной или ";
  std::cout << barbersPerDay << " для ежедневной работы!" << "\n";
  } else {
  std::cout << "Так как за месяц требуется подстричь " << men << " мужчин, ежемесячно должно работать " << barbersPerMonth << " барберов ";
  std::cout << "или " << everyDayNeededBarbers << " ежедневно." << "\n";
  std::cout << "Так как у вас уже работает " << barbers << " барберов, нанимать никого не нужно! Вам хватает барберов для успешной работы!" << "\n";
  std::cout << "Советуем Вам сократить количество барберов на " << deleteBarbers << " для оптимизации финансов!" << "\n";
  }
}