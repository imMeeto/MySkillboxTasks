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

  int servedByBarber = 8;

  float barbersPerMonth = men / 8;
  float needBarbers = barbersPerMonth - barbers;
  float barbersPerDay;
  barbersPerDay = needBarbers / 30;

  std::cout << "Так как в месяц требуется подстричь " << men << " мужчин, каждый день дожно работать " << barbersPerDay << " барберов." << "\n";
  float necessaryToHire = needBarbers / 30 - barbers;
  std::cout << "Так как у вас уже работает " << barbers << " барберов, необходимо нанять " << necessaryToHire << " барберов." << "\n";
}