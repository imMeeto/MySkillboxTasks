#include <iostream>

int main() {
  std::cout << "*Bulls and cows game.*\n";

  std::string firstNumber, secondNumber;

  while (true) {
    std::cout << "[Player 1]: Input the desired number (4 digits): ";
    std::cin >> firstNumber;

    if (firstNumber.length() != 4) {
      std::cout << "[Error]: Input 4 digits.\n";
      continue;
    } else {
      break;
    }
  }

    while (true) {
    std::cout << "[Player 2]: Input the second number (4 digits): ";
    std::cin >> secondNumber;

    if (secondNumber.length() != 4) {
      std::cout << "[Error]: Input 4 digits.\n";
      continue;
    } else {
      break;
    }
  }

  int bullsCount = 0;
  int cowsCount = 0;

  for (int i = 0; i < 4; ++i) {
      if (firstNumber[i] == secondNumber[i]) {
          ++bullsCount;
      }
  }

  for (int i = 0; i < 4; ++i) { // Для каждой цифры i от 0 до 3 в загаданном числе
      for (int j = 0; j < 4; ++j) { // проверяем каждую цифру j от 0 до 3 в названном числе
          if (i != j && firstNumber[i] == secondNumber[j]) {
              ++cowsCount;
              break;
          }
      }
  }

  // Корректировка коров, так как одна цифра может быть учтена несколько раз
  cowsCount = std::min(cowsCount, 4 - bullsCount);
  
  std::cout << "[Game]: Bulls: " << bullsCount << ", cows: " << cowsCount << "\n";

  return 0;
}