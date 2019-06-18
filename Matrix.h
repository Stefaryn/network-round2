#ifndef MATRIX_H
#define MATRIX_H
class Matrix{
  float **data;
  public:
    static void mat_malloc(float **);
    Matrix();  
    Matrix(float **);
};
#endif
