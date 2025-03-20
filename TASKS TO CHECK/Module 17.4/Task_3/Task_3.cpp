#include <iostream>

bool substr(const char* a, const char* b) 
{
  while (*a != '\0')
  {
    while (*a != '\0' && *b != 0 && *a == *b)
    {
      *a++;
      *b++;
    }
    
    if (*b == '\0')
    {
      return true;
    }
    *a++;
  }
  return false;
}

int main() 
{
  const char* a = "Hello world!";
  const char* b = "wor";
  const char* c = "banana";

  std::cout << std::boolalpha;
  std::cout << substr(a, b) << " " << substr(a, c);

  return 0;
}