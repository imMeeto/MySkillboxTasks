#include <iostream>

int main() {
  std::cout << "Производство игровых деревянных кубиков 5x5x5 см." << "\n";

  float X, Y, Z;
  std::cout << "Введите размеры бруска: ";
  std::cout << "X: ";
  std::cin >> X;
  std::cout << "Y: ";
  std::cin >> Y;
  std::cout << "Z: ";
  std::cin >> Z;

  const int CUBE = 125; // 5*5*5
  float woodenBar = X * Y * Z;
  float makedCubes = woodenBar / CUBE;

  std::cout << "Из этого бруска можно изготовить: " << makedCubes << " кубиков.";



  std::cout << "Из них можно составить набор из " << // code << " кубиков.";


}