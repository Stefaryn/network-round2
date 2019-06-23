#ifndef VECTOR_H
#define VECTOR_H


class Vector {
  //private:
    //int length;
    //float *vector; 

  public:
    int length;
    float *vector; 
    Vector();
    Vector(int);
    Vector(int, float *);
    ~Vector();

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
