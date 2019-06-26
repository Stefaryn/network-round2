#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
  float **data;
  int rows;
  int cols;
  public:
    static void validate_op(Matrix &, Matrix &, char);
    static int  mat_malloc(float **&, int, int, float def = 0);
    static void mat_copy(float **&, float **, int, int, int, int);
    static void mat_free(float **, int);
    Matrix(float **, int, int);
    Matrix(int, int, float def = 0);
    ~Matrix();
    void print(int precision = 2);
    // getters
    int num_rows(){ return rows;};
    int num_cols(){ return cols;};
    float * operator [](const int index);
    // operator overloads
    friend Matrix operator +(Matrix &, Matrix &);
    friend Matrix operator -(Matrix &, Matrix &);
    friend Matrix operator *(Matrix &a, Matrix &b);
    friend Matrix& operator +=(Matrix &, Matrix&);
    friend Matrix& operator -=(Matrix &, Matrix&);
    friend Matrix& operator *(float s, Matrix& a);
    friend Matrix& operator *(Matrix& a, float s);
};

#endif
