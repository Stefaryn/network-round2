#include <iostream>
#include "matrix.h"
#include "vector.h"

int main(int argc, char *argv[]){
  Matrix A(5, 5, 1);
  Matrix B(5, 5, 1);
  Matrix C = A*B;
  C.print();
}
