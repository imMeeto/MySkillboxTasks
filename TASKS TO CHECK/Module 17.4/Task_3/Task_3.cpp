#include <iostream>

bool substr(const char* a, const char* b) 
{
  while (*a != '\0')
  {

    const char* pa = a;
    const char* pb = b;

    while (*pa != '\0' && *pb != 0 && *pa == *pb)
    {
      pa++;
      pb++;
    }
    
    if (*pb == '\0')
    {
      return true;
    }

    a++;
  }
  return false;
}

int main() 
{
  const char* a = "11132";
  const char* b = "112";
  const char* c = "banana";

  std::cout << std::boolalpha;
  std::cout << substr(a, b) << " " << substr(a, c);

  return 0;
}