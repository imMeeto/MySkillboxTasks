#include <iostream>
#include <string>

int main() {
  std::cout << "Программа для печати важных объявлений." << "\n";

  int symbolCount, exclamationCount;

  std::cout << "Введите общую длину колонтитула: ";
  std::cin >> symbolCount;

  std::cout << "Введите количество восклицательных знаков: ";
  std::cin >> exclamationCount;

if (exclamationCount > symbolCount) {
  std::cout << "Количество восклицательных знаков не может превышать общую длинну!" << "\n";
  return 1;
}


  int totalTildes = symbolCount - exclamationCount;
  int leftTildes = totalTildes / 2;
  int rightTildes = totalTildes - leftTildes;

  std::string result;

    for (int i = 0; i < leftTildes; i++) {
      result += '~';
    }
    for (int i = 0; i < exclamationCount; i++) {
      result += '!';
    }
    for (int i = 0; i < rightTildes; i++) {
      result += '~';
    }

  std::cout << result;

  return 0;
}
