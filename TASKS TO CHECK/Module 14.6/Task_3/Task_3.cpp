#include <iostream>
#include <vector>

bool areMatrixEqual(int A[4][4], int B[4][4]) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (A[i][j] != B[i][j]) {
        return false;
      }
    }
  }
  return true;
}