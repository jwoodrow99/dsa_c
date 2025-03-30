#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

Vector vector_init(size_t unit_size, int initial_capacity_count){
  Vector v;
  v.unit_size = unit_size;
  v.capacity = (initial_capacity_count * unit_size);
  v.size = 0;
  v.data = malloc(v.capacity);
  return v;
}

void grow(Vector* v){
  v->capacity = v->capacity * 2;
  v->data = realloc(v->data, v->capacity);
}

void shrink(Vector* v){
  v->capacity = v->capacity / 2;
  v->data = realloc(v->data, v->capacity);
}

void resize(Vector* v){
  float used = ((float)(v->unit_size * v->size) / v->capacity);
  if(used >= 0.75){
    grow(v);
  } else if (used <= 0.25) {
    shrink(v);
  }
}

void vector_set(Vector* v, int i, void* data_item){
  if( i < v->size ){
    void* ptr = (v->data + (i * (int)v->unit_size));
    memcpy(ptr, data_item, v->unit_size);
  }
}

void* vector_get(Vector* v, int i){
  if( i < v->size ){
    void* ptr = (v->data + (i * (int)v->unit_size));
    return ptr;
  }
}

void vector_remove(Vector* v, int i){
  if( i < v->size ){
    void* ptr = (v->data + (i * (int)v->unit_size));
    void* after_ptr = ptr + v->unit_size;
    size_t remaining_size = v->capacity - ((v->unit_size * i));
    memcpy(ptr, after_ptr, remaining_size);
    v->size--;
    resize(v);
  }
}

void vector_push(Vector* v, void* data_item){
  resize(v);
  void* ptr = (v->data + (v->size * (int)v->unit_size));
  memcpy(ptr, data_item, v->unit_size);
  v->size++;
}

void vector_pop(Vector* v){
  void* ptr = (v->data + ((v->size - 1) * (int)v->unit_size));
  v->size--;
  resize(v);
}

void vector_unshift(Vector* v, void* data_item){
  resize(v);
  v->size++;
  memcpy(v->data, (v->data - v->unit_size), (v->size * v->unit_size));
  vector_set(v, 0, data_item);
}

void vector_shift(Vector* v){
  memcpy((v->data - v->unit_size), v->data, (v->size * v->unit_size));
  v->size--;
  resize(v);
}

void vector_print(Vector* v){
  printf("data pointer: %p\n", v->data);
  printf("unit_size %zu\n", v->unit_size);
  printf("size: %d\n", v->size);
  printf("capacity: %zu\n", v->capacity);
}
