#include <iostream>

int main() 
{
  std::string intPart;
  std::string fracPart;

  std::cout << "Input integer part of the number: ";
  std::cin >> intPart;

  std::cout << "Input fraction part of the number: ";
  std::cin >> fracPart;

  std::string strNumber = intPart + "." + fracPart;

  double resultMum = std::stod(strNumber);

  std::cout << "Result: " << resultMum << "\n";
  return 0;
}