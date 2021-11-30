// The program shows the  implementation in "sequence.h" file of the Sequence 
//    ADT using a singly linked list.


#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include <assert.h>


struct llnode {
  int item;
  struct llnode *next;
};


struct sequence {
  struct llnode *data;
  int length;
};


// See "sequence.h" file for detail documentataion
struct sequence *sequence_create(void) {
  struct sequence *seq = malloc(sizeof(struct sequence));
  seq->data = NULL;
  seq->length = 0;
  return seq;  
}


// See 'sequence.h" file for detail documentation
void sequence_destroy(struct sequence *seq) {
  assert(seq);
  struct llnode *node = seq->data;
  struct llnode *nextnode = NULL;
  while (node) {
    nextnode = node->next;
    free(node);
    node = nextnode;
  }
  free(seq);
}


// See 'sequence.h" file for detail documentation
int sequence_length(const struct sequence *seq) {
  assert(seq);
  return seq->length;
}


// See 'sequence.h" file for detail documentation
int sequence_item_at(const struct sequence *seq, int pos) {
  assert(seq);
  assert(0 <= pos && pos < seq->length);
  struct llnode *node = seq->data;
  for (int i = 0; i < pos; ++i) {
    node = node->next;
  }
  return node->item;
}


// See 'sequence.h" file for detail documentation
void sequence_insert_at(struct sequence *seq, int pos, int val) {
  assert(seq);
  assert(0 <= pos && pos <= seq->length);

  if (pos == 0) {
    struct llnode *node = malloc(sizeof(struct llnode));
    node->item = val;
    node->next = seq->data;
    seq->data = node;
  } else {
    struct llnode *node = seq->data;
    for (int i = 1; i < pos; ++i) {
      node = node->next;
    }
    struct llnode *newnode = malloc(sizeof(struct llnode));
    newnode->item = val;
    newnode->next = node->next;
    node->next = newnode;
  }
  seq->length += 1;
}


// See 'sequence.h" file for detail documentation
int sequence_remove_at(struct sequence *seq, int pos) {
  assert(seq);
  assert(0 <= pos && pos < seq->length);

  int val = 0;
  struct llnode *node = NULL;
  struct llnode *parent = NULL;
  if (pos == 0) {
    node = seq->data->next;
    val = seq->data->item;
    free(seq->data);
    seq->data = node;
  } else {
    node = seq->data;
    parent = node;
    while (pos > 0) {
      parent = node;
      node = node->next;
      pos -= 1;
    }
    val = node->item;
    parent->next = node->next;
    free(node);
  }
  seq->length -= 1;
  return val;
}


// See 'sequence.h" file for detail documentation
void sequence_print(const struct sequence *seq) {
  assert(seq);
  if (seq->data == NULL) {
    printf("[empty]\n");
  } else {
    printf("[");
    struct llnode *node = seq->data;
    for (int i = 0; i < seq->length; ++i) {
      printf("%d", node->item);
      node = node->next;
      if (i != seq->length - 1) {
        printf(",");
      }
    }
    printf("]\n");   
  }
}


