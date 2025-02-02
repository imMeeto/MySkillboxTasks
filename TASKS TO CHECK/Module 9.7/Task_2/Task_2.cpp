#include <iostream>

int main() {
  std::cout << "Check if the float number is written correctly.\n";

  std::string number;
  std::cout << "Input float number: ";
  std::cin >> number;

  if (number[0] >= '0' && number[0] <= '9' || number[0] == '.' || number[0] == '-') {
    std::cout << "Yes!\n";
  } else {
    std::cout << "No!\n";
  }
  
}