// The file implement generic array ADT.


#include "array.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


struct array {
  int capacity;
  void **data;
  void (*destroy)(void *);
  void (*print)(const void *);
};


// See array.h for documentation
struct array *array_create(int capacity,
                           void (*destroy)(void *),
                           void (*print)(const void *)) {
  assert(capacity >= 0);
  assert(destroy && print);
  struct array *arr = malloc(sizeof(struct array));
  arr->data = malloc(sizeof(void *) * capacity);
  for (int i = 0; i < capacity; ++i) {
    arr->data[i] = NULL;
  }
  arr->capacity = capacity;
  arr->destroy = destroy;
  arr->print = print;
  return arr;
}


// See array.h for documentation
void array_destroy(struct array *arr) {
  assert(arr);
  for (int i = 0; i < arr->capacity; ++i) {
    if (arr->data[i]) {
      arr->destroy(arr->data[i]);
    }
  }
  free(arr->data);
  free(arr);
}


// See array.h for documentation
void *array_at_get(struct array *arr, int index) {
  assert(arr);
  assert(0 <= index && index < arr->capacity);
  return arr->data[index];
}


// See array.h for documentation
void array_at_set(struct array *arr, void *data, int index) {
  assert(arr && data);
  assert(0 <= index && index < arr->capacity);
  arr->data[index] = data;  
}


// See array.h for documentation
void array_print(const struct array *arr) {
  assert(arr);
  for (int i = 0; i < arr->capacity; ++i) {
    if (arr->data[i] == NULL) {
      printf("[empty]\n");
    } else {
      arr->print(arr->data[i]);
    }
  }
}


// See array.h for documentation
void array_sort(struct array *arr, bool (*pred)(const void *, const void *)) {
  assert(arr && pred);
  void *temp = NULL;
  for (int i = 1; i < arr->capacity; ++i) {
    for (int j = i - 1; j > -1; --j) {
      if (pred(arr->data[j + 1], arr->data[j])) {
        temp = arr->data[j + 1];
        arr->data[j + 1] = arr->data[j];
        arr->data[j] = temp;
      } else {
        break;
      }
    }
  }
}


