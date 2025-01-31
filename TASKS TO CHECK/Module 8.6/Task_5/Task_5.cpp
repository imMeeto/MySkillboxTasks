#include <iostream>
#include <cmath>

int main() {
  std::cout << "Расчёт среднего темпа бега.\n";

  float kilometers = 0.0f, seconds = 0.0f;
  int minutes = 0;
  int pace = 0;
  int allPace = 0; // Инициализация переменной

  std::cout << "Привет, Сэм! Сколько километров ты сегодня пробежал? ";
  std::cin >> kilometers;

  // Проверка ввода на количество километров
  if (kilometers <= 0) {
    std::cout << "Количество километров должно быть положительным числом.\n";
    return 1;
  }

  for (int kmCount = 1; kmCount <= kilometers; kmCount++) {
    std::cout << "Какой у тебя был темп на километре " << kmCount << "? ";
    std::cin >> pace;

    // Проверка ввода на темп
    if (pace < 0) {
      std::cout << "Темп не может быть отрицательным.\n";
      return 1;
    }

    allPace += pace;
  }

  float arithmeticMean = allPace / kilometers;

  minutes = (arithmeticMean) / 60;
  seconds = static_cast<int>(arithmeticMean) % 60; 

  std::cout << "Твой средний темп за тренировку: " << minutes << " минут " << seconds << " секунд.\n";

  return 0;
}
