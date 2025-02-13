#include <iostream>
#include <string>

std::string lastNames[10];

int main() {
  std::cout << "*Check who lives in the apartment.*\n";
  std::cout << "Input 10 last names of people:\n";

  for (int i = 0; i < 10; i++) {
      std::cout << "- last name " << i + 1 << ": ";
      std::cin >> lastNames[i];
    } 

    int apartmentsNum[3];
    std::cout << "Input 3 apartment numbers:\n";
      for (int i = 0; i < 3; i++) {
        while (true) {
        std::cout << "- apartment " << i + 1 << ": ";
        std::cin >> apartmentsNum[i];

        if (apartmentsNum[i] >= 1 && apartmentsNum[i] <= 10) {
          break;
        } else {
          std::cout << "Invalid input. Please input a number between 1 and 10.\n";
        }
      }
    }
    
    std::cout << "Result: \n";
    for (int i = 0; i < 3; i++) {
      int apartmentNum = apartmentsNum[i];
      if (apartmentNum >= 1 || apartmentNum <= 10) {
        std::cout << "In apartement " << apartmentNum << " live: " << lastNames[apartmentNum - 1] << "\n";
      } else {
        std::cout << "Invalid apartment number " << apartmentNum <<  "!" << "\n";
      }
    }
    
    return 0;
}