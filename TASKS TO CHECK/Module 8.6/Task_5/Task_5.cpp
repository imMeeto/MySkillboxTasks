#include <iostream>
#include <cmath>

int main() {
  std::cout << "Расчёта среднего темпа бега.\n";

  float kilometers = 0.0f, seconds = 0.0f;
  int minutes = 0;
  int pace = 0;

  std::cout << "Привет, Сэм! Сколько километров ты сегодня пробежал? ";
  std::cin >> kilometers;

int allPace;
  for (int kmCount = 1; kilometers >= kmCount; kmCount++) {
    std::cout << "Какой у тебя был темп на километре " << kmCount << "? ";
    std::cin >> pace;
    allPace += pace;
  }

  int arithmeticMean = (allPace / kilometers);

  minutes = arithmeticMean / 60;
  seconds = round(arithmeticMean % 60);

  std::cout << "Твой средний темп за тренировку: " << minutes << " минут " << seconds << " секунд.\n";

  return 0;
}