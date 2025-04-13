#include <iostream>
#include <fstream>
#include <string>

bool isPNG(std::string filePath)
{
  std::ifstream file(filePath, std::ios::binary);

  if (!file)
  {
    std::cout << "Error! The file did not open!\n";
    return false;
  }
  
  char header[4];
  file.read(header, 4);

  if (file.gcount() < 4)
  {
    std::cout << "Error! The file is too small!\n";
    return false;
  }

  bool is_PNG = (header[0] == -119 &&
                 header[1] == 'P' &&
                 header[2] == 'N' &&
                 header[3] == 'G');
  
  file.close();
  return is_PNG;
}

int main()
{
  std::string filePath;
  std::cout << "Input the path of file: ";
  std::getline(std::cin, filePath);

  if (isPNG(filePath))
  {
    std::cout << "This is a PNG file.\n";
  }
  else
  {
    std::cout << "This is not a PNG file.\n";
  }
  
  return 0;
}