#include <iostream>

#include "Vector.h"

Vector::Vector(){
  Vector::length = 0;
  Vector::vector = nullptr;
}

Vector::Vector(int inLength, float *inVec){
  Vector::length = inLength;
  for (int i = 0 ; i < inLength ; ++i) {
    Vector::vector[i] = inVec[i]; 
  }
}

Vector& Vector::operator+(Vector &addVec){
  if(Vector::length != addVec.length){
    fprintf(stderr, "ERROR: undefined vector addition of sized %d and %d\n", Vector::length, addVec.length);
    exit(EXIT_FAILURE);
  }

  for (int i = 0 ; i < Vector::length ; ++i){
    Vector::vector[i] += addVec.vector[i];
  }

  return Vector&;  
}

int main(){
  /*
  int l1 = 3;
  int l2 = 3;
  float *v1 = (float *) malloc(sizeof(float) * l1); 
  float *v2 = (float *) malloc(sizeof(float) * l2);

  for (int i = 0 ; i < l1 ; ++i){
    v1[i] = i;
  }

  for (int i = 0 ; i < l2 ; ++i){
    v2[i] = l2 - i;
  }
  
  Vector vec1(l1, v1);
  Vector vec2(l2, v2);

  vec1 = vec1 + vec2;

  for (int i = 0 ; i < l1 ; ++i){
    printf("%d\n", vec1.vector[i]);
  }
  */ 
  return 0;
}
