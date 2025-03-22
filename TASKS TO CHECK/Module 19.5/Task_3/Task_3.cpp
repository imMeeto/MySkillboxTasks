#include <iostream>
#include <fstream>

int main()
{
  std::string filePath;
  std::cout << "Enter the path to the file: ";
  std::getline(std::cin, filePath);

  std::ifstream file;
  file.open(filePath, std::ios::binary);

  if (!file.is_open())
  {
    std::cout << "Error! File was not found!\n";
    return 1;
  }

  int bufferSize = 1024;
  char buffer[bufferSize];

  while (file)
  {
    file.read(buffer, bufferSize);
    std::streamsize bytesRead = file.gcount();
    std::cout.write(buffer, bytesRead);
  }
  
  file.close();
  
  return 0;

}