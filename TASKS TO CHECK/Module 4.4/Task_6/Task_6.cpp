#include <iostream>

int main() {
  int people;
  int barbersCount;
  std::cout << "---Рассчет необходимого количества барберов.---" << "\n";

    while (true) {
      std::cout << "Введите количество человек проживающих в городе: ";
      std::cin >> people;
        if (people < 1000) {
          std::cout << "В городе не может проживать так мало людей! Введите значение от 1000!" << "\n";
        } else {
          break;
        } 
    }

  int mensCount = people / 2;
  std::cout << "По статистике, в городе проживает 50% мужчин, поэтому мужчин: " << mensCount << "\n";

    while (true) {
      std::cout << "Введите количество уже работающих барберов: ";
      std::cin >> barbersCount;
        if (barbersCount < 0) {
          std::cout << "Вы ввели неверное значение! Если у вас нет барберов, то введите 0." << "\n";
        } else {
          break;
        } 
    }
  
  std::cout << "Производим рассчет..." << "\n";
  std::cout << "------------------------------------------------" << "\n";

  int mansPerBarber = 8; // один человек в час, смена 8 часов

  // Сколько человек успеет постричь барбер за месяц?
  int mansPerBarberPerMonth = mansPerBarber * 30;
  std::cout << "Один барбер стрижет столько клиентов в месяц " << mansPerBarberPerMonth << "\n";

  // Сколько нужно барберов чтобы постричь mensCount человек в месяц?
  int requiredBarbersCount = mensCount / mansPerBarberPerMonth;
  if (requiredBarbersCount * mansPerBarberPerMonth < mensCount) {
  requiredBarbersCount += 1;
  }

  if (mensCount % mansPerBarberPerMonth != 0)
  {
    requiredBarbersCount + 1;
  }

  std::cout << "Необходимое число барберов: " << requiredBarbersCount << "\n";

  // Сколько человек успеют постричь requiredBarbersCount за месяц?
  std::cout << requiredBarbersCount << " барбера могут постричь " <<
  requiredBarbersCount * mansPerBarberPerMonth << " мужчин за месяц!\n";

  // Сравниваем с количестом имеющихся барберов
  if (requiredBarbersCount > barbersCount) {
  std::cout << "Нужно больше барберов!!!\n";
  }

  if (requiredBarbersCount <= barbersCount) {
  std::cout << "Барберов хватает!!!\n";
  }
}