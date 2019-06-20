#include <iostream>
#include "matrix.h"

int main(int argc, char *argv[]){
  Matrix A(5, 5, 1);
  Matrix B(5, 5, 0);
  
  Matrix M = A+B;
  Matrix C = M-M;
  M.print(1);
  C.print(1);
}
