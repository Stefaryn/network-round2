#ifndef VECTOR_H
#define VECTOR_H


class Vector {
  //private: // I thought we agreed to make these private?
    //int length;
    //float *vector; 

  public:
    int length;
    float *vector; 
    Vector();
    Vector(int); // add a default parameter for all the values in the vector like i did in the matrix class
    Vector(int, float *);
    ~Vector();
    float& operator [](int);
    int get_length();
};

Vector *operator+(Vector&, Vector&);
Vector *operator-(Vector&, Vector&);
Vector &operator+=(Vector&, Vector&);
Vector &operator-=(Vector&, Vector&);

Vector *operator*(Vector&, float);
Vector *operator*(float, Vector&);
Vector &operator*=(Vector&, float);
Vector &operator*=(float, Vector&);

float dotProduct(Vector&, Vector&);
#endif
