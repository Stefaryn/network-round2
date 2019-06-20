#include <iostream>

#include "Vector.h"

// Constructor no parameters
Vector::Vector(){
  Vector::length = 0;
  Vector::vector = nullptr;
}

// Constructor just length, initializes to 0
Vector::Vector(int inLength){
  Vector::length = inLength;
  Vector::vector = new float [inLength];
  for (int i = 0 ; i < inLength ; ++i) {
    Vector::vector[i] = 0; 
  }
}

// Constructor given all inputs 
Vector::Vector(int inLength, float *inVec){
  Vector::length = inLength;
  Vector::vector = new float [inLength];
  for (int i = 0 ; i < inLength ; ++i) {
    Vector::vector[i] = inVec[i]; 
  }
}

// Deconstructor
Vector::~Vector(){
    delete Vector::vector;
}

/*
// Overloaded += operator (not yet working)
Vector& operator+=(Vector& addVec){
  if(Vector::length != addVec.length){
    fprintf(stderr, "ERROR: undefined vector addition of sized %d and %d\n", Vector::length, addVec.length);
    exit(EXIT_FAILURE);
  }
    
  for (int i = 0 ; i < Vector::length ; ++i){
    Vector::vector[i] += addVec.vector[i];
  }
}
*/

// Overloaded + operator
Vector *operator+(Vector &vec1, Vector &vec2){
  if(vec1.length != vec2.length){
    fprintf(stderr, "ERROR: undefined vector addition of sized %d and %d\n", vec1.length, vec2.length);
    exit(EXIT_FAILURE);
  }

  Vector *newVec = new Vector(vec1.length); 
  for (int i = 0 ; i < vec1.length ; ++i){
    newVec->vector[i] = vec1.vector[i] + vec2.vector[i];
  }

  return newVec;  
}

// Main for some basic testing, can turn this into a test function later
int main(){
  
  int l1 = 3;
  int l2 = 3;
  float *v1 = (float *) malloc(sizeof(float) * l1); 
  float *v2 = (float *) malloc(sizeof(float) * l2);

  for (int i = 0 ; i < l1 ; ++i){
    v1[i] = (float) i;
  }

  for (int i = 0 ; i < l2 ; ++i){
    v2[i] = (float) i;
  }
  
  Vector vec1(l1, v1);
  Vector vec2(l2, v2);

  Vector *vec3 = vec1 + vec2;

  for (int i = 0 ; i < l1 ; ++i){
    printf("%f +", vec1.vector[i]);
    printf("%f = ", vec2.vector[i]);
    printf("%f\n", vec3->vector[i]);
  }
   
  return 0;
}
