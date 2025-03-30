#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vector.h"

void printVector(Vector* v){
  vector_print(v);
  for(int i = 0; i < v->size; i++){
    printf("[%d]: %d\n", i, ((int*)v->data)[i]);
  }
}

void vectorTest(){
  Vector v = vector_init(sizeof(int), 10);

  // init data: insert number of random integers
  srand(time(NULL));
  for(int i = 0; i < 30; i++){
    int data = rand();
    vector_push(&v, &data);
  }

  printVector(&v);  

  // vector_push(&v, &(int){10});
  // vector_remove(&v, 4);
  vector_shift(&v);

  printVector(&v);
}

int main(int argc, char *argv[])
{
  vectorTest(); 

  return EXIT_SUCCESS;
}


