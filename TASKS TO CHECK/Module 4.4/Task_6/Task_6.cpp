#include <iostream>

int main() {
  int barbersCount;
  int mensCount;
  std::cout << "---Рассчет необходимого количества барберов.---" << "\n";

  std::cout << "Введите количество мужчин проживающих в городе: ";
  std::cin >> mensCount;

  std::cout << "Введите количество уже работающих барберов: ";
  std::cin >> barbersCount;

  std::cout << "Производим рассчет..." << "\n";
  std::cout << "------------------------------------------------" << "\n";

  int mansPerBarber = 8; // один человек в час, смена 8 часов

  // Сколько человек успеет постричь барбер за месяц?
  int mansPerBarberPerMonth = mansPerBarber * 30;
  std::cout << "Один барбер стрижет столько клиентов в месяц: " << mansPerBarberPerMonth << "\n";

  // Сколько нужно барберов чтобы постричь mensCount человек в месяц?
  int requiredBarbersCount = mensCount / mansPerBarberPerMonth;

  if (mensCount % mansPerBarberPerMonth != 0) {
    requiredBarbersCount += 1;
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