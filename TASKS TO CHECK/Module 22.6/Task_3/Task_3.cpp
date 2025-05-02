#include <iostream>
#include <map>
#include <string>

bool isAnagram(const std::string& first, const std::string& second)
{
  if (first.length() != second.length())
  {
    return false;
  }
  
  std::map<char, int> charCount;

  for (char c : first)
  {
    charCount[c]++;
  }

  for (char c : second)
  {
    charCount[c]--;
  }

  for (const std::pair<char, int>& pair : charCount)
  {
    if (pair.second != 0)
    {
      return false;
    }
  }
  
  return true;
}

int main ()
{
std::string first, second;
std::cout << "Enter the first line: ";
std::getline(std::cin, first);
std::cout << "Enter the second line: ";
std::getline(std::cin, second);

if (isAnagram(first, second))
{
  std::cout << "These words are annagrams!\n";
}
else
{
  std::cout << "These words are not annagrams!\n";
}

return 0;
}
