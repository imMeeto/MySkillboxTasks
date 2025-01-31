#include <iostream>

int main() {
  std::cout << "Производство игровых деревянных кубиков 5x5x5 см." << "\n";

  const int CUBE_X = 5, CUBE_Y = 5, CUBE_Z = 5;
  const int CUBE_FULL = CUBE_X * CUBE_Y * CUBE_Z; // основной кубик 5*5*5 см

  float woodBarX, woodBarY, woodBarZ;
  std::cout << "Введите размеры бруска: " << "\n";
  std::cout << "X: ";
  std::cin >> woodBarX;
  std::cout << "Y: ";
  std::cin >> woodBarY;
  std::cout << "Z: ";
  std::cin >> woodBarZ;

  float woodBarFull = woodBarX * woodBarY * woodBarZ;
  float makedCubes = woodBarFull / CUBE_FULL;

  int willMadeCubes = makedCubes % CUBE_FULL;

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