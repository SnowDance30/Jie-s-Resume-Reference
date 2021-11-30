// This is a very poor test client for the sequence module

// You are strongly recommended to build your own test client
// note: sequence_print is not tested

#include <assert.h>
#include <stdio.h>
#include "sequence.h"

// is_odd(n) determines if n is odd
bool is_odd(int n) {
  return n % 2;
}

// sqr(n) calculates n * n
int sqr(int n) {
  return n * n;
}

int linear_func(int n) {
  return -n + 5;
}

int main(void) {
  
  struct sequence s = {0};
  sequence_init(&s);
  sequence_print(&s);
  assert(sequence_length(&s) == 0);
  sequence_insert_at(&s, 0, 1);
  sequence_insert_at(&s, 0, 2);
  sequence_insert_at(&s, 0, 3);
  sequence_insert_at(&s, 0, 4);
  sequence_insert_at(&s, 0, 5);
  assert(sequence_length(&s) == 5);
  assert(sequence_item_at(&s, 2) == 3);  
  sequence_print(&s);
  
  struct sequence s3 = {0};
  sequence_init(&s3);
  sequence_build(&s3, linear_func, 5);
  sequence_print(&s3);
  assert(sequence_length(&s3) == 5);
  assert(sequence_equiv(&s, &s3));
  
  assert(sequence_remove_at(&s, 1) == 4);
  assert(sequence_length(&s) == 4);
  assert(sequence_item_at(&s, 2) == 2);
  
  sequence_init(&s);
  assert(sequence_length(&s) == 0);
  sequence_print(&s);
  assert(sequence_equiv(&s, &s3) == false);
  sequence_build(&s, sqr, 5);
  assert(sequence_equiv(&s, &s3) == false);
  sequence_print(&s);
  
  sequence_filter(&s3, is_odd);
  sequence_print(&s3);
  assert(sequence_length(&s3) == 3);
  sequence_append(&s3, &s);
  assert(sequence_length(&s3) == 8);
  sequence_print(&s3);
  
  struct sequence s4 = {0};
  sequence_init(&s4);
  sequence_insert_at(&s4, 0, 1);
  sequence_insert_at(&s4, 0, 1);
  sequence_insert_at(&s4, 0, 1);
  sequence_remove_dups(&s4);
  assert(sequence_length(&s4) == 1);
  sequence_print(&s4);
  sequence_init(&s4);
  sequence_insert_at(&s4, 0, 1);
  sequence_insert_at(&s4, 1, 3);
  sequence_insert_at(&s4, 2, 6);
  sequence_remove_dups(&s4);
  assert(sequence_length(&s4) == 3);
  sequence_insert_at(&s4, 1, 1);
  sequence_insert_at(&s4, 3, 1);
  sequence_insert_at(&s4, 5, 1);
  sequence_insert_at(&s4, 6, 3);
  sequence_print(&s4);
  sequence_remove_dups(&s4);
  sequence_print(&s4);
  assert(sequence_length(&s4) == 3);
  sequence_build(&s4, sqr, 0);
  assert(sequence_length(&s4) == 0);
  sequence_filter(&s4, is_odd);
  
  struct sequence s1 = {0};
  sequence_init(&s1);
  sequence_insert_at(&s1, 0, 1);
  
  struct sequence s2 = {0};
  sequence_init(&s2);
  sequence_insert_at(&s2, 0, 1);
  
  assert(sequence_equiv(&s1, &s2));
  
  assert(sequence_length(&s1) == 1);
  assert(sequence_remove_at(&s1, 0) == 1);
  assert(sequence_length(&s1) == 0);
  sequence_append(&s1, &s2);
  assert(sequence_length(&s1) == 1);
  sequence_append(&s1, &s2);
  assert(sequence_length(&s1) == 2);
  sequence_remove_dups(&s1);
  assert(sequence_length(&s1) == 1);
  sequence_build(&s1, sqr, 2);
  assert(sequence_length(&s1) == 2);
  sequence_filter(&s1, is_odd);
  assert(sequence_length(&s1) == 1);
}
