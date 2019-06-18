#include <iostream>

#include "matrix.h"

// frees a 2d matrix object, not a deconstructor 
// for a Matrix object
void Matrix::mat_free(float **mat, int rows){
  for(int i = 0; i < rows; i++){
    free(mat[i]);
  }
  free(mat);
}

// return 0 if exited normally
// optional parameter def is 0
int Matrix::mat_malloc(float **&dst, int r, int c, float def){
  int ret = 0;
  // allocate
  dst = (float **)malloc(sizeof(float*)*r);
  if(dst == nullptr){
    ret = 1;
  }
  for(int i = 0; i < r; i++){
    dst[i] = (float *)malloc(sizeof(float)*c);
    if(dst[i] == nullptr){
      ret = 1;
    }
    // init
    for(int j = 0; j < c; j++){
      dst[i][j] = def;
    }
  }
  return ret;
}

void Matrix::mat_copy(float **&dst, float **src, int r1, int c1, int r2, int c2){
  // validate
  if(r1 != r2 || c1 != c2){
    std::cerr << "ERROR (mat_copy): dimensions do not match.\n" << std::endl;
  }
  // copy
  for(int i = 0; i < r1; i++){
    for(int j = 0; j < c1; j++){
      dst[i][j] = src[i][j];
    }
  } 
}

// constructor with float matrix
Matrix::Matrix(float **src_, int rows_, int cols_, float def){ 
  Matrix::mat_malloc(data, rows_, cols_, def);
  Matrix::mat_copy(data, src_, rows_, cols_, rows_, cols_);
  rows = rows_;
  cols = cols_;
}

// constructor without float matrix
Matrix::Matrix(int rows_, int cols_, float def){ 
  Matrix::mat_malloc(data, rows_, cols_, def);
  rows = rows_;
  cols = cols_;
}


// destructors
Matrix::~Matrix(){
  Matrix::mat_free(data, rows);
}
