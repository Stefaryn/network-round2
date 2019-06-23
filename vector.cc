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

// Overloaded + operator, returns new vector
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

// Overloaded - operator, returns new vector v1 - v2
Vector *operator-(Vector &vec1, Vector &vec2){
  if(vec1.length != vec2.length){
    fprintf(stderr, "ERROR: undefined vector addition of sized %d and %d\n", vec1.length, vec2.length);
    exit(EXIT_FAILURE);
  }

  Vector *newVec = new Vector(vec1.length); 
  for (int i = 0 ; i < vec1.length ; ++i){
    newVec->vector[i] = vec1.vector[i] - vec2.vector[i];
  }

  return newVec;  
}

// Overloaded += operator, vec1 += vec2
Vector &operator+=(Vector &vec1, Vector &vec2){
  if(vec1.length != vec2.length){
    fprintf(stderr, "ERROR: undefined vector addition of sized %d and %d\n", vec1.length, vec2.length);
    exit(EXIT_FAILURE);
  }

  for (int i = 0 ; i < vec1.length ; ++i){
    vec1.vector[i] += vec2.vector[i];
  }

  return vec1;  
}

// Overloaded -= operator, vec1 -= vec2
Vector &operator-=(Vector &vec1, Vector &vec2){
  if(vec1.length != vec2.length){
    fprintf(stderr, "ERROR: undefined vector addition of sized %d and %d\n", vec1.length, vec2.length);
    exit(EXIT_FAILURE);
  }

  for (int i = 0 ; i < vec1.length ; ++i){
    vec1.vector[i] -= vec2.vector[i];
  }

  return vec1;  
}

// Scalars that return a new vector
Vector *operator*(Vector &vec, float scalar){
  Vector *newVec = new Vector(vec.length); 
  for (int i = 0 ; i < vec.length ; ++i){
    newVec->vector[i] = vec.vector[i] * scalar;
  }

  return newVec;  
}
	
Vector *operator*(float scalar , Vector &vec){
  Vector *newVec = new Vector(vec.length); 
  for (int i = 0 ; i < vec.length ; ++i){
    newVec->vector[i] = vec.vector[i] * scalar;
  }

  return newVec;  
}
	
// Scalars that change a vector in place
Vector &operator*=(Vector &vec, float scalar){
  for (int i = 0 ; i < vec.length ; ++i){
    vec.vector[i] *= scalar;
  }

  return vec;  
}

Vector &operator*=(float scalar, Vector &vec){
  for (int i = 0 ; i < vec.length ; ++i){
    vec.vector[i] *= scalar;
  }

  return vec;  
}

// Dot product of two vectors
float dotProduct(Vector &vec1, Vector &vec2){
  if(vec1.length != vec2.length){
    fprintf(stderr, "ERROR: undefined vector addition of sized %d and %d\n", vec1.length, vec2.length);
    exit(EXIT_FAILURE);
  }

  float sum = 0.0;

  for (int i = 0 ; i < vec1.length ; ++i){
    sum += vec1.vector[i] * vec2.vector[i];
  }

  return sum;
}

// Main for some basic testing, can turn this into a test function later
int main(){
  
  int l1 = 3;
  int l2 = 3;
  float *v1 = (float *) malloc(sizeof(float) * l1); 
  float *v2 = (float *) malloc(sizeof(float) * l2);

  for (int i = 0 ; i < l1 ; ++i){
    v1[i] = (float) i + 1;
  }

  for (int i = 0 ; i < l2 ; ++i){
    v2[i] = (float) i + 1;
  }
  
  Vector vec1(l1, v1);
  Vector vec2(l2, v2);
  
  printf("vec1 is: ");
  for (int i = 0 ; i < l1 ; ++i){
    printf("%f, ", vec1.vector[i]);
  }
  printf("\n\n");

  printf("vec2 is: ");
  for (int i = 0 ; i < l2 ; ++i){
    printf("%f ", vec2.vector[i]);
  }
  printf("\n\n");

  Vector *vec3 = vec1 + vec2;

  printf("vec3 (vec1 + vec2) is: ");
  for (int i = 0 ; i < l1 ; ++i){
    printf("%f ", vec3->vector[i]);
  }
  printf("\n\n");

  vec2 += *vec3;

  printf("vec2 (vec2 += vec3) is now: ");
  for (int i = 0 ; i < l2 ; ++i){
    printf("%f ", vec2.vector[i]);
  }
  printf("\n\n");

  vec2 *= .5;  
  printf("vec2 scaled by .5 is: ");
  for (int i = 0 ; i < l2 ; ++i){
    printf("%f ", vec2.vector[i]);
  }
  printf("\n\n");

  vec1 *= 2.0;  
  printf("vec1 scaled by 2.0 is: ");
  for (int i = 0 ; i < l1 ; ++i){
    printf("%f ", vec1.vector[i]);
  }
  printf("\n\n");

  Vector *vec4 = vec2 * 2.0;
  printf("vec4 = vec2 scaled by 2.0 is: ");
  for (int i = 0 ; i < l2 ; ++i){
    printf("%f ", vec4->vector[i]);
  }
  printf("\n\n");

  Vector *vec5 = .5 * vec1;
  printf("vec5 = vec1 scaled by .5 is: ");
  for (int i = 0 ; i < l1 ; ++i){
    printf("%f ", vec5->vector[i]);
  }
  printf("\n\n");

  printf("Dot product of vec1 and vec2 = %f\n\n", dotProduct(vec1, vec2));

  return 0;
}



