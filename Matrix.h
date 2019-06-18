#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
  float **data;
  int rows;
  int cols;
  public:
    static int  mat_malloc(float **&, int, int, float def = 0);
    static void mat_copy(float **&, float **, int, int, int, int);
    static void mat_free(float **, int);
    Matrix(float **, int, int, float def = 0);
    Matrix(int, int, float def = 0);
    ~Matrix();
};

#endif
