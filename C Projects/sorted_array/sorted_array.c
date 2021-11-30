// The module shows the implementation of "sorted_array.h" file.


#include "sorted_array.h"
#include "merge_sort.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// See sorted_array.h for documentation
// required time: O(n)
// actual time: O(1)
void sarray_init(struct sarray *arr) {
  assert(arr);
  arr->len = 0;
}

// See sorted_array.h for documentation
// time: O(1)
void sarray_insert(struct sarray *arr, int value) {
  assert(arr);
  assert(arr->len < 100);
  assert(0 <= value && value <= 999);
  if (arr->len != 100) {
    arr->data[arr->len] = value;
    arr->len += 1;
  }
}

// See sorted_array.h for documentation
// time: O(n)
void sarray_remove(struct sarray *arr, int value) {
  assert(arr);
  assert(0 <= value && value <= 999);
  int max = arr->len;
  bool check = false;
  for (int i = 0; i < max; ++i) {
    if (arr->data[i] != value && check == false) {
      continue;
    } else if (arr->data[i] == value && check == false) {
      arr->len -= 1;
      check = true;
    } else {
      arr->data[i-1] = arr->data[i];
    }
  }
}


// See sorted_array.h for documentation
// time: O(n log n)
int sarray_at(struct sarray *arr, int index) {
  assert(arr);
  assert(0 <= index && index < arr->len);
  merge_sort(arr->data, arr->len);
  return arr->data[index];
}

// See sorted_array.h for documentation
// time: O(n)
bool sarray_exist(struct sarray *arr, int value) {
  assert(arr);
  assert(0 <= value && value <= 999);
  for (int i = 0; i < arr->len; ++i) {
    if (arr->data[i] == value) {
      return true;
    }
  }
  return false;
}

// See sorted_array.h for documentation
// time: O(n log n)
void sarray_print(struct sarray *arr) {
  assert(arr);
  if (arr->len == 0) {
    printf("[]\n");
  } else {
    merge_sort(arr->data, arr->len);
    printf("[");
    for (int i = 0; i < arr->len; ++i) {
      if (i != arr->len -1) {
        printf("%d, ", arr->data[i]);
      } else {
        printf("%d", arr->data[i]);
      }
    }
    printf("]\n");
  }
}

  
  