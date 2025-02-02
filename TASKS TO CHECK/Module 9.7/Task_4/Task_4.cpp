#include <iostream>

int main() {
  std::cout << "Bulls and cows game.\n";

  std::string firstNumber;
  std::string secondNumber;

  while (true) {
    std::cout << "Input the desired number: ";
    std::cin >> firstNumber;

    if (firstNumber.length() > 4) {
      std::cout << "Number is too long. Input 4 digits.\n";
      continue;
    } else {
      break;
    }
  }

  while (true) {
    std::cout << "Input the second number: ";
    std::cin >> secondNumber;

    if (secondNumber.length() > 4) { 
      std::cout << "Number is too long. Input 4 digits.\n";
      continue;
    } else {
      break;
    }
  }
}