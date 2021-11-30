// The module provides struct and fucntions implemented in "sorted_array.c" file

#include <stdbool.h>

struct sarray {
  int data[100];
  int len;
};


// The following applies to all functions:
// requires: all arr pointers are valid (not NULL)

// sarray_init(arr) initializes arr to be an empty sarray.
// effects: mutate arr->len
// requried time: O(n)
// actual time: O(1)
void sarray_init(struct sarray *arr);

// sarray_insert(arr, value) inserts value into arr.
// requires: arr must have available space to store value
//           value must be between 0 an 999 (both inclusive)
// effects:  may mutate arr->len
//           may mutate arr->data
// time:     O(1)
void sarray_insert(struct sarray *arr, int value);


// sarray_remove(arr, value) removes one instance of value from arr, if value
//   exists in arr; otherwise, arr remains unchanged.
// requires: value must be between 0 an 999 (both inclusive)
// effects:  may mutate arr->len
//           may mutate arr->data
// time:     O(n)
void sarray_remove(struct sarray *arr, int value);


// sarray_at(arr, index) returns the value at index from arr.
// requires: index must be between 0 and 99 (both inclusive)
//           0 <= index < arr->len
// effects:  may mutate arr->data
// time:     O(n log n)
int sarray_at(struct sarray *arr, int index);


// sarray_exist(arr, value) returns true if value is in arr, and false
//   otherwise.
// requires: value must be between 0 an 999 (both inclusive)
// effects:  no effects
// time:     O(n)
bool sarray_exist(struct sarray *arr, int value);


// sarray_print(arr) prints arr.
// effects: produces console output
//          may mutate arr->data
// time:    O(n log n)
void sarray_print(struct sarray *arr);
