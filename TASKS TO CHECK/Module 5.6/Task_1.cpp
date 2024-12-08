#include <iostream>

int main() 
{
std::cout <<  "Проверьте, правильным ли эшелоном летит самолёт." << "\n";

int flightLevel;
std::cout << "Введите эшелон полета в метрах: ";
std::cin >> flightLevel;

int speed;
std::cout << "Введите скорость самолета: ";
std::cin >> speed;

std::cout << "------------------------------" << "\n";

if (flightLevel < 9000 || flightLevel > 9500 && speed < 750 || speed > 850)
{
  std::cout << "Это не верный эшелон полета." << "\n";
} else { 
  std::cout << "Это верный эшелон полета." << "\n";
}

return 0;
}

