#include <stdbool.h>

// A generic array
struct array;

// array_create(capacity, destroy, print) creates a generic array with a given
//   capacity. The function-pointers destroy and print are used to destroy and
//   print the stored data.
//   The value of data is never NULL when calling destroy or print.
// effects:  allocates memory; client must call array_destroy.
// requires: capacity must be non-negative
// time:     O(n)
struct array *array_create(int capacity,
                           void (*destroy)(void *data),
                           void (*print)(const void *data));

// array_destroy(arr) frees all resources used by arr and the stored data.
// effects: arr and stored data becomes invalid
// time:    O(n)
void array_destroy(struct array *arr);

// array_at_get(arr, index) returns the data in arr stored at index. If there
//   is no data stored, the function returns NULL.
// requires: index must be between 0 (inclusive) and arr's capacity (exclusive)
// time:     O(1)
void *array_at_get(struct array *arr, int index);

// array_at_set(arr, data, index) stores data in arr at index. If there was data
//   already stored at index, it is overwritten and NOT destroyed. To destroy
//   the data, client could call struct_destroy(array_at_get(arr, index)) first.
// effects:  mutates arr
// requires: index must be between 0 (inclusive) and arr's capacity (exclusive)
// time:     O(1)
void array_at_set(struct array *arr, void *data, int index);

// array_print(arr) prints the content of arr. Empty cells are printed as
//   "[empty]".
// effects: produces output
// time:    O(n)
void array_print(const struct array *arr);

// array_sort(arr, pred) sorts arr using the predicate pred. Be aware that data1
//   and data2 may be NULL when calling pred.
// effects: mutates arr
// time:    O(n^2)
void array_sort(struct array *arr,
                bool (*pred)(const void *data1, const void *data2));