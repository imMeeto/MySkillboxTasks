#include <iostream>
#include <vector>

int main() 
{
  std::vector<std::vector <float>> A(4, std::vector<float>(4));

  std::cout << "Input matrix elements: \n";
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      std::cin >> A[i][j];
    }
  }

  std::vector<float> B(4);
  std::cout << "Input vector elements: \n";
  for (int i = 0; i < 4; ++i)
  {
    std::cin >> B[i];
  }
  
  std::vector<float> C(4, 0.0f);

  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      C[i] += A[i][j] * B[j];
    }
  }

  std::cout << "Result vector: \n";
  for (int i = 0; i < 4; ++i)
  {
    std::cout << C[i] << " ";
  }
  std::cout << "\n";
  
  return 0;
}