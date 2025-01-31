#include <iostream>
#include <cmath>

int main() {
  std::cout << "Расчёт среднего темпа бега.\n";

  float kilometers = 0.0f;

  std::cout << "Привет, Сэм! Сколько километров ты сегодня пробежал? ";
  std::cin >> kilometers;

  // Проверка ввода на количество километров
  if (kilometers <= 0) {
    std::cout << "Количество километров должно быть положительным числом.\n";
    return 1;
  }

  int totalSeconds = 0;

  for (int kmCount = 1; kmCount <= kilometers; kmCount++) {
    std::cout << "Какой у тебя был темп на километре " << kmCount << "? ";
    int pace;
    std::cin >> pace;

    if (pace < 0) {
      std::cout << "Темп не может быть отрицательным.\n";
      return 1;
    }

    totalSeconds += pace;
  }

  int averagePace = std::round(static_cast<float>(totalSeconds) / kilometers);

  int minutes = averagePace / 60;
  int seconds = averagePace % 60; 

  std::cout << "Твой средний темп за тренировку: " << minutes << " минут " << seconds << " секунд.\n";

  return 0;
}
