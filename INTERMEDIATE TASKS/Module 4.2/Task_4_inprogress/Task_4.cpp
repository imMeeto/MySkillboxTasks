#include <iostream>

int main() {
  int people;
  int barbers;
  std::cout << "---Рассчет необходимого количества барберов.---" << "\n";
  std::cout << "Введите количество человек проживающих в городе: " ;
  std::cin >> people;
  int men = people / 2;
  std::cout << "По статистике, в городе проживает 50% мужчин, поэтому мужчин: " << men << "\n";

  std::cout << "Введите количество уже работающих барберов:  " ;
  std::cin >> barbers;

  float barbersPerMonth = men / 8;
  float barbersPerDay;
  float everyDayNeededBarbers = barbersPerMonth / 30;
  float needBarbers = barbersPerMonth - barbers;
  barbersPerDay = needBarbers / 30;

  std::cout << "Так как за месяц требуется подстричь " << men << " мужчин, ежемесячно должно работать " << barbersPerMonth << " барберов ";
  std::cout << "или ежедневно " << everyDayNeededBarbers << " барберов." << "\n";
  std::cout << "Так как у вас уже работает " << barbers << " барберов, необходимо нанять " << needBarbers << " барберов для ежемесячной или ";
  std::cout << barbersPerDay << " барберов для ежедневной работы." << "\n";
}