#include <iostream>

int main() {
  std::cout << "Bulls and cows game.\n";

  std::string firstNumber, secondNumber;

  std::cout << "Input the desired number: ";

  while (true) {
    if (firstNumber.length() != 4 || secondNumber.length() != 4) {
      std::cout << "Number is too long. Input 4 digits!\n";
      continue;
    } else {
      break;
    }
  }

  int bullsCount = 0;
  int cowsCount = 0;
  
  return 0;
}