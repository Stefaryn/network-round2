#include <iostream>
#include "matrix.h"

int main(int argc, char *argv[]){
  int rows = 5;
  int cols = 5;
  float **ptr = nullptr;
  Matrix::mat_malloc(ptr, rows, cols);
  //Matrix m(rows, cols);
  //Matrix m2(ptr, rows, cols);
  Matrix::mat_free(ptr, rows);
}
