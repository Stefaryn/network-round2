#include <iostream>
#include "matrix.h"

int main(int argc, char *argv[]){
  Matrix A(5, 5, 1);
  A = 8*A;
  A.print(3);
  std::cout << "A[1][1]: " << A[1][1] << std::endl; 
}
