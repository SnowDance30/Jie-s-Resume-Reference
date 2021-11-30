// This file is a test client of "sequence.c" file.

#include <stdio.h>
#include <assert.h>
#include "sequence.h"

int main(void) {
  struct sequence *seq = sequence_create();
  sequence_print(seq);
  assert(sequence_length(seq) == 0);
  sequence_insert_at(seq, 0, 27);
  sequence_insert_at(seq, 1, 50);
  sequence_print(seq);
  assert(sequence_item_at(seq, 1) == 50);
  assert(sequence_item_at(seq, 0) == 27);
  assert(sequence_length(seq) == 2);
  sequence_insert_at(seq, 0, 1);
  assert(sequence_length(seq) == 3);
  sequence_insert_at(seq, 2, 3);
  assert(sequence_length(seq) == 4);;
  assert(sequence_item_at(seq, 0) == 1);
  assert(sequence_item_at(seq, 1) == 27);
  assert(sequence_item_at(seq, 2) == 3);
  assert(sequence_item_at(seq, 3) == 50);
  sequence_print(seq);
  assert(sequence_remove_at(seq, 2) == 3);
  assert(sequence_remove_at(seq, 2) == 50);
  assert(sequence_remove_at(seq, 0) == 1);
  assert(sequence_remove_at(seq, 0) == 27);
  sequence_print(seq);
  sequence_destroy(seq);
}
