#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime> 

int main()
{
  std::srand(std::time(nullptr));

  std::cout << "*** Create binary paintings ***\n";
  std::cout << "To get started, input the full file path: \n";
  std::string filePath;
  std::getline(std::cin, filePath);

  std::ofstream file(filePath);
  if (!file.is_open())
  {
    std::cout << "Error opening file: " << filePath << std::endl;
    exit(1);
  }

  int width, height;

  std::cout << "\nInput the width of the picture (in pixels): ";
  std::cin >> width;
  std::cout << "Input the height of the painting (in pixels): ";
  std::cin >> height;

  if (width <= 0 || height <= 0)
  {
      std::cerr << "Error: Width and height must be positive numbers!" << std::endl;
      return 1;
  }

  for (int i = 0; i < height; ++i)
  {
      for (int j = 0; j < width; ++j)
      {
          file << (std::rand() % 2);
      }
      file << std::endl;
  }

  file.close();

  std::cout << "\nThe binary image has been successfully saved to a file:\n" << filePath << std::endl;

  return 0;
}