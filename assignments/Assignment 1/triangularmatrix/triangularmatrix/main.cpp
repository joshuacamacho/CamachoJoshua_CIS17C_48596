// Joshua Camacho
// 09/01/14
// CIS-17C-48596
// Assignment 1 - Triangular Matrix
#include "TriangularMatrix.h"

int main(){
  TriangularMatrix<float> triangle(5);
  triangle.print();
  
  TriangularMatrix<int> inttriangle(5);
  inttriangle.print();
  return 0;
}