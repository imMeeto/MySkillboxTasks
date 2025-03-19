#include <iostream>
#include <sstream>

int main()
{
  double a, b;
  std::string buffer;
  char operation;

  std::cout << "*Simple calculator.*\n";
  std::cout << "Input expression in the format <number-1><operation><number-2>: ";

  std::cin >> buffer;

  std::stringstream buffer_stream(buffer);
  buffer_stream >> a >> operation >> b;

  double result = 0.0;

    if (operation == '+')
    {
      result = a + b;
    } 
    else if (operation == '-')
    {
      result = a - b;
    } 
    else if (operation == '*')
    {
      result = a * b;
    } 
    else if (operation = '/')
    {
      if (b != 0)
      {
        result = a / b;
      } 
      else
      {
        std::cout << "Error: Division by zero!\n";
        return 1;
      }
    }

  std::cout << "Result: " << result << "\n";
  return 0;
}
