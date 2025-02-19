#include <iostream>
#include <vector>

int main() {

  std::cout << "*Create a ring-buffer of 20 digits.*\n";
  std::cout << "Сontrol: \n";
  std::cout << "- to result, input: -1\n";
  std::cout << "- to exit, input: -2\n";
  

  std::vector<int> db(20);
  int count = 0; // Количество элементов в буфере
  int pos = 0;   // Текущая позиция для записи

  while (true) 
  {
    std::cout << "Input number: ";
    int number;
    std::cin >> number;

    if (number == -1)
    {
      std::cout << "Output: ";
      if (count <= 20)
      {
          // Если элементов меньше или равно 20, выводим их все
          for (int i = 0; i < count; ++i)
          {
              std::cout << db[i] << " ";
          }
      } 
      else
      {
          // Если элементов больше 20, выводим последние 20 элементов
          for (int i = 0; i < 20; ++i)
          {
              std::cout << db[(pos + i) % 20] << " ";
          }
      }
      std::cout << "\n";
    } 
    else if (number == -2)
    {
      std::cout << "See you later!\n";
      return 0;
    }
    else
    {
        db[pos] = number;
        pos = (pos + 1) % 20; // Переходим к следующей позиции (по кругу)
        count++; // Увеличиваем счетчик элементов
    }
  }

  return 0;
}