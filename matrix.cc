#include <iostream>
#include <iomanip>

#include "matrix.h"
#include "vector.h"

// frees a 2d matrix object, not a deconstructor 
// for a Matrix object
void Matrix::mat_free(float **mat, int rows){
  for(int i = 0; i < rows; i++){
    delete[] mat[i];
  }
  delete[] mat;
}

// return 0 if exited normally
// optional parameter def is 0
int Matrix::mat_malloc(float **&dst, int r, int c, float def){
  int ret = 0;
  // allocate
  dst = new float*[r];
  if(dst == nullptr){
    ret = 1;
  }
  for(int i = 0; i < r; i++){
    dst[i] = new float[c];
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

// used from matrix multiplication
void Matrix::validate_op(Matrix &a, Matrix &b, char op){
  int r1 = a.num_rows();
  int r2 = b.num_rows();
  int c1 = a.num_rows();
  int c2 = b.num_rows();
  if(op == '+' || op == '-' || op == 'c'){
    if(r1 != r2 || c1 != c2){
      std::cerr << "ERROR (operator " << op << "): undefined matrix operation between a " << r1 << "x" << c1 << " and a " << r2 << "x" << c2 << ".\n";
      exit(EXIT_FAILURE);
    }
  }
  if(op == '*'){
    if(c1 != r1){
      std::cerr << "ERROR (operator " << op << "): undefined matrix operation between a " << r1 << "x" << c1 << " and a " << r2 << "x" << c2 << ".\n"; 
      exit(EXIT_FAILURE);
    }
  } 
}


// constructor with float matrix
Matrix::Matrix(float **src_, int rows_, int cols_){ 
  Matrix::mat_malloc(data, rows_, cols_);
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

// default precision parameter is set to 2
void Matrix::print(int precision){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      std::cout << std::setprecision(precision) << data[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

// operator overloads
Matrix operator +(Matrix &a, Matrix &b){
  int r1 = a.num_rows();
  int r2 = b.num_rows();
  int c1 = a.num_rows();
  int c2 = b.num_rows();
  Matrix::validate_op(a,b,'+');  
 
  // make temp
  float **temp = nullptr;
  Matrix::mat_malloc(temp,r1,c1);

  // add
  for(int i = 0; i < r1; i++){
    for(int j = 0; j < c1; j++){
      temp[i][j] = a[i][j] + b[i][j];
    }
  }
  
  // return new matrix
  Matrix result(temp,r1,r2);
  Matrix::mat_free(temp, r1);
  return result;
}

Matrix operator -(Matrix &a, Matrix &b){
  int r1 = a.num_rows();
  int r2 = b.num_rows();
  int c1 = a.num_rows();
  int c2 = b.num_rows();
  Matrix::validate_op(a,b,'-');  

  // make temp
  float **temp = nullptr;
  Matrix::mat_malloc(temp,r1,c1);

  // subtract
  for(int i = 0; i < r1; i++){
    for(int j = 0; j < c1; j++){
      temp[i][j] = a[i][j] - b[i][j];
    }
  }
  
  // return new matrix
  Matrix result(temp,r1,r2);
  Matrix::mat_free(temp, r1);
  return result;
}

Matrix operator *(Matrix &a, Matrix &b){
  Matrix::validate_op(a,b,'*');
  int r = a.num_rows(), c = b.num_cols();
  Matrix res(r,c);
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      for(int k = 0; k < c; k++){
        res[i][j] += a[i][k]*b[j][k];
      }
    }
  }
  return res;
}

float * Matrix::operator [](const int index){ 
  if(index > rows){
    std::cerr << "Index out of bounds: " << index << " > " << rows << std::endl;
  }
  return data[index];
}


Matrix& operator +=(Matrix &a, Matrix &b){
  Matrix::validate_op(a, b, '+');
  for(int i = 0, r = a.num_rows(), c = a.num_cols(); i < r; i++){
   for(int j = 0; j < c; j++){
     a[i][j] += b[i][j];
   } 
  }
  return a;
}

Matrix& operator -=(Matrix &a, Matrix &b){
  Matrix::validate_op(a, b, '-');
  for(int i = 0, r = a.num_rows(); i < r; i++){
   for(int j = 0, c = a.num_cols(); j < c; j++){
     a[i][j] -= b[i][j];
   } 
  }
  return a;
}

Matrix& operator *(float s, Matrix& a){
  for (int i = 0, r = a.num_rows(); i < r; i++){
    for(int j = 0, c = a.num_cols(); j < c; j++){
      a[i][j] *= s;
    }
  }
  return a;
}

Matrix& operator *(Matrix& a, float s){
  for (int i = 0, r = a.num_rows(); i < r; i++){
    for(int j = 0, c = a.num_cols(); j < c; j++){
      a[i][j] *= s;
    }
  }
  return a;
}

// matrix and vector nonsense
Vector operator *(Matrix &m, Vector &v){
  int r = m.num_rows(), c = m.num_cols(), l = v.get_length();
  if(c != l){
    std::cerr << "ERROR: Invalid matrix-vector multiplication" << std::endl;
    exit(EXIT_FAILURE);
  } 
  Vector temp(r);
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      temp[i] += m[i][j] * v[j];
    }
  }
  return temp;
}


