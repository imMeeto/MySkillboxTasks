#include <iostream>

int main() {
  std::cout << "Производство игровых деревянных кубиков 5x5x5 см." << "\n";

  float X, Y, Z;
  std::cout << "Введите размеры бруска: " << "\n";
  std::cout << "X: ";
  std::cin >> X;
  std::cout << "Y: ";
  std::cin >> Y;
  std::cout << "Z: ";
  std::cin >> Z;

  const int CUBE = 125; // 5*5*5
  float woodenBar = X * Y * Z;
  float makedCubes = woodenBar / CUBE;

  std::cout << "Из этого бруска можно изготовить: " << makedCubes << " кубиков." << "\n"; //должно быть 49 потому что не хватает на ещё 1.355 кубик

  int set = 2;
  for (int i = 0; i < set; i++) {
    set = set*set*set;
    if (set > makedCubes) {
      break;
    }
    
  }


  std::cout << "Из них можно составить набор из " << set << " кубиков."; //должен получиться набор из 27 кубиков

}