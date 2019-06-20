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
    //Vector& operator+=(Vector&);

};

Vector *operator+(Vector&, Vector&);

#endif
