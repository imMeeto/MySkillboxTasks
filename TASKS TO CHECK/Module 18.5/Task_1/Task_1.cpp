#include <iostream>
#include <vector>

void swapvec(std::vector<int>& vec, int* arr)
{
  for (int i = 0; i < vec.size(); ++i)
  {
      int temp = arr[i];
      arr[i] = vec[i];
      vec[i] = temp;
  }
}

int main() 
{
  std::vector<int> a = {2, 2, 2, 2};
  int b[] = {3, 2, 1, 0}; 

  swapvec(a, b);

  for(int i = 0; i < 4; ++i) std::cout << a[i];

  std::cout << "\n";

  for(int i = 0; i < 4; ++i) std::cout << b[i];

  return 0;
}