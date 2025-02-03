#include <iostream>

int main() {
  std::cout << "Bulls and cows game.\n";

  std::string firstNumber, secondNumber;

  while (true) {
    std::cout << "Input the desired number (4 digits): ";
    std::cin >> firstNumber;

    if (firstNumber.length() != 4) {
      std::cout << "Error! Input 4 digits.\n";
      continue;
    } else {
      break;
    }
  }

    while (true) {
    std::cout << "Input the second number (4 digits): ";
    std::cin >> secondNumber;

    if (secondNumber.length() != 4) {
      std::cout << "Error! Input 4 digits.\n";
      continue;
    } else {
      break;
    }
  }

  int bullsCount = 0;
  int cowsCount = 0;

  // Подсчёт быков
  for (int i = 0; i < 4; ++i) {
      if (firstNumber[i] == secondNumber[i]) {
          ++bullsCount;
      }
  }

  // Подсчёт коров
  for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
          if (i != j && firstNumber[i] == secondNumber[j]) {
              ++cowsCount;
              break;
          }
      }
  }

  // Корректировка коров, так как одна цифра может быть учтена несколько раз
  cowsCount = std::min(cowsCount, 4 - bullsCount);
  
  std::cout << "Bulls: " << bullsCount << ", cows: " << cowsCount << "\n";

  return 0;
}