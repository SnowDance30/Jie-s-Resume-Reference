// The module shows the implementation of int sequence ADT in sequence.h

#include <stdio.h>
#include "sequence.h"
#include <stdlib.h>
#include <assert.h>

/////////////////////////////////////////////////////////////////////////////
// Helper functions:

// move_elements(seq, count, record) moves elements which is marked in record
//   in data field of seq, and at last len filed of seq minus count.
// effects: modifies seq
static void move_elements(struct sequence *seq, int count, int *record) {
  assert(seq && record);
  for (int i = 0; i < seq->len - 1; ++i) {
    if (record[i] == 1) {
      for (int j = i + 1; j < seq->len; ++j) {
        if (record[j] == 0) {
          seq->data[i] = seq->data[j];
          record[i] = 0;
          record[j] = 1;
          break;
        }
      }
    }
  }
  seq->len -= count;
}

/////////////////////////////////////////////////////////////////

// The following applies to all functions:
// requires: all seq pointers are valid (not NULL)
//           all function pointers are valid (not NULL)

// see "sequence.h" for documentation
void sequence_init(struct sequence *seq) {
  assert(seq);
  seq->len = 0;
  seq->maxlen = 1024;
}  

// see "sequence.h" for documentation
int sequence_length(const struct sequence *seq) {
  assert(seq);
  return seq->len;
}

// see "sequence.h" for documentation
int sequence_item_at(const struct sequence *seq, int pos) {
  assert(seq);
  assert(0 <= pos && pos < seq->len);
  return seq->data[pos];
}

// see "sequence.h" for documentation
void sequence_insert_at(struct sequence *seq, int pos, int val) {
  assert(seq);
  assert(0 <= pos && pos <= seq->len && seq->len < seq->maxlen);
  if (seq->len == 0) {
    seq->data[0] = val;
    seq->len += 1;
  } else {
    for (int i = seq->len; i > pos; --i) {
      seq->data[i] = seq->data[i - 1];
    }
    seq->data[pos] = val;
    seq->len += 1;
  }
}

// see "sequence.h" for documentation
int sequence_remove_at(struct sequence *seq, int pos) {
  assert(seq);
  assert(0 <= pos && pos < seq->len);
  int val = seq->data[pos];
  for (int i = pos; i < seq->len; ++i) {
    seq->data[i] = seq->data[i + 1];
  }
  seq->len -= 1;
  return val;
}


// see "sequence.h" for documentation
bool sequence_equiv(const struct sequence *seq1, const struct sequence *seq2) {
  assert(seq1 && seq2);
  bool check = true;
  if (seq1->len == seq2->len) {
    for (int i = 0; i < seq1->len; ++i) {
      if (seq1->data[i] != seq2->data[i]) {
        check = false;
        break;
      }
    }
  } else {
    return false;
  }
  if (check == true) {
    return true;
  } else {
    return false;
  }
}

// see "sequence.h" for documentation
void sequence_print(const struct sequence *seq) {
  assert(seq);
  if (seq->len == 0) {
    printf("[empty]\n");
  } else {
    printf("[");
    for (int i = 0; i < seq->len - 1; ++i) {
      printf("%d,", seq->data[i]);
    }
    printf("%d]\n", seq->data[seq->len - 1]);
  }
}


// see "sequence.h" for documentation
void sequence_build(struct sequence *seq, int (*f)(int), int n) {
  assert(seq);
  assert(f);
  assert(0 <= n && n <= seq->maxlen);
  for (int i = 0; i < n; ++i) {
    seq->data[i] = f(i);
  }
  seq->len = n;
}


// see "sequence.h" for documentation
void sequence_filter(struct sequence *seq, bool (*f)(int)) {
  assert(seq);
  assert(f);
  int count = 0;
  int record[1024] = {0};
  for (int i = 0; i < seq->len; ++i) {
    if (!f(seq->data[i])) {
      record[i] = 1;
      count += 1;
    }
  }
  move_elements(seq, count, record);
}



// see "sequence.h" for documentation
void sequence_append(struct sequence *seq1, const struct sequence *seq2) {
  assert(seq1 && seq2 && seq1 != seq2);
  assert(seq1->len + seq2->len <= seq1->maxlen);
  for (int i = seq1->len; i < seq1->len + seq2->len; ++i) {
    seq1->data[i] = seq2->data[i - seq1->len];
  }
  seq1->len = seq1->len + seq2->len;
}




// see "sequence.h" for documentation
void sequence_remove_dups(struct sequence *seq) {
  assert(seq);
  int count = 0;
  int record[1024] = {0};
  for (int i = seq->len - 1; i > 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      if (seq->data[i] == seq->data[j]) {
        record[i] = 1;
        count += 1;
        break;
      }
    }
  }
  move_elements(seq, count, record);
}

