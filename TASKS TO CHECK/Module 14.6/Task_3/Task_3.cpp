#include <iostream>
#include <vector>

bool areMatrixEqual(int A[4][4], int B[4][4]) 
{
  for (int i = 0; i < 4; ++i) 
  {
    for (int j = 0; j < 4; ++j) 
    {
      if (A[i][j] != B[i][j]) return false;
    }
  }
  return true;
}

void convertToDiagonal(int matrix[4][4]) {
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      if (i != j) matrix[i][j] = 0;
    }
  }
}

void printMatrix(int matrix[4][4])
{
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main()
{
  std::cout << "*Convert matrix to diagonal.*\n";

  int A[4][4];
  int B[4][4];

  std::cout << "Input matrix A:\n";
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      std::cin >> A[i][j];
    }
  }
  
  std::cout << "Input matrix B:\n";
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      std::cin >> B[i][j];
    }
  }

  if(areMatrixEqual(A, B))
  {
    std::cout << "Matrix A and B are equal.\n";
    convertToDiagonal(A);
    std::cout << "Matrix after conversion to diagonal:\n";
    printMatrix(A);
  } else {
    std::cout << "Matrix are not equal!\n";
  }
  
  return 0;
}
