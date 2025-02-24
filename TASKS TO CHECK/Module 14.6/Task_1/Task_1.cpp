#include <iostream>
#include <vector>

int main() {
  int utensils[2][6] = {{3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3}};
  int plates[2][6] = {{2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2}};
  int chairs[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};

  utensils[0][0] += 1;
  utensils[0][1] += 1;
  plates[0][0] += 1;
  plates[0][1] += 1;

  chairs[0][4] += 1; // Добавлен стул для ребёнка на пятое место первого ряда
  plates[1][2] -= 1; // Украдена ложка с третьего места второго ряда
  utensils[0][0] -= 1; // VIP-персона поделилась ложкой
  utensils[1][2] += 1; // Ложка передана тому, у кого её украли
  plates[0][0] -= 1;

  std::cout << "Utensils in result: \n";
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      std::cout << utensils[i][j] << " ";
    }
    std::cout << "\n";
  }
  
  std::cout << "Plates in result: \n";
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      std::cout << plates[i][j] << " ";
    }
    std::cout << "\n";
  }
  
  std::cout << "Chairs in result: \n";
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      std::cout << chairs[i][j] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}       