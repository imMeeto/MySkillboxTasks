#include <fstream>
#include <vector>
#include <iostream>

int maint()
{
  std::vector<char> vec;
  std::ifstream Words;
  Words.open("C:\\VS Code\\VS Code Projects\\MySkillboxTasks\\TASKS TO CHECK\\Module 19.5\\Task_1\\Words.txt");
  
  for (int i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i] << "\n";
  }

}