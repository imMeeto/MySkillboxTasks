#include <iostream>

void reverse(int* arr)
{
  for (int i = 0; i < 5; ++i)
  {
    int temp = arr[i];
    arr[i] = arr[9 - i];
    arr[9 - i] = temp;
  }
  
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << "Array before reverse: ";
  for (int i = 0; i < 10; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
  
  reverse(arr);

  std::cout << "Array after reverse: ";
  for (int i = 0; i < 10; i++)
  {
    std::cout << arr[i] << " ";
  }
  
  return 0;
}