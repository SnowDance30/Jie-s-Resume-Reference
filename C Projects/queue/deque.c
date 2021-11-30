// The module shows the implementation in "deque.h" a double ended queue ADT.

#include "deque.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct llnode {
  int item;
  struct llnode *prev;
  struct llnode *next;
};

struct deque {
  struct llnode *front;
  struct llnode *back;
};


// See "deque.h" file for detial documentation.
struct deque *deque_create(void) {
  struct deque *deq = malloc(sizeof(struct deque));
  deq->front = NULL;
  deq->back = NULL;
  return deq;
}


// See "deque.h" file for detial documentation.
void deque_destroy(struct deque *deq) {
  assert(deq);
  struct llnode *next = NULL;
  for (struct llnode *node = deq->front; node != NULL; node = next) {
    next = node->next;
    free(node);
  }
  free(deq);
}


// See "deque.h" file for detial documentation.
bool deque_is_empty(const struct deque *deq) {
  assert(deq);
  return !deq->front;
}


// See "deque.h" file for detial documentation.
void deque_insert_front(int item, struct deque *deq) {
  assert(deq);
  struct llnode *node = malloc(sizeof(struct llnode));
  node->item = item;
  if (deq->front == NULL) {
    deq->front = node;
    deq->back = node;
    node->next = NULL;
    node->prev = NULL;
  } else {
    node->next = deq->front;
    node->next->prev = node;
    node->prev = NULL;
    deq->front = node;
  }
}


// See "deque.h" file for detial documentation.
int deque_front(const struct deque *deq) {
  assert(deq);
  assert(deq->front);
  return deq->front->item;
}


// See "deque.h" file for detial documentation.
int deque_remove_front(struct deque *deq) {
  assert(deq);
  assert(deq->front);
  int item = deq->front->item;
  struct llnode *front = deq->front;
  if (front->next == NULL) {
    deq->front = NULL;
    deq->back = NULL;
  } else {
    deq->front = deq->front->next;
    deq->front->prev = NULL;
  }
  free(front);
  return item;
}


// See "deque.h" file for detial documentation.
void deque_insert_back(int item, struct deque *deq) {
  assert(deq);
  struct llnode *node = malloc(sizeof(struct llnode));
  node->item = item;
  if (deq->back == NULL) {
    deq->front = node;
    deq->back = node;
    node->next = NULL;
    node->prev = NULL;
  } else {
    node->prev = deq->back;
    node->next = NULL;
    node->prev->next = node;
    deq->back = node;
  }
}


// See "deque.h" file for detial documentation.
int deque_back(const struct deque *deq) {
  assert(deq);
  assert(deq->back);
  return deq->back->item;
}


// See "deque.h" file for detial documentation.
int deque_remove_back(struct deque *deq) {
  assert(deq);
  assert(deq->back);
  struct llnode *node = deq->back;
  int item = node->item;
  if (node->prev == NULL) {
    deq->back = NULL;
    deq->front = NULL;
  } else {
    deq->back = node->prev;
    deq->back->next = NULL;
  }
  free(node);
  return item;
}


// See "deque.h" file for detial documentation.
void deque_print(const struct deque *deq) {
  assert(deq);
  if (deq->front == NULL) {
    printf("[empty]\n");
  } else {
    printf("[%d", deq->front->item);
    for (struct llnode *node = deq->front->next; node != NULL; node = node->next) {
      printf(",%d", node->item);
    }
    printf("]\n");
  }
}


// See "deque.h" file for detial documentation.
void deque_print_reverse(const struct deque *deq) {
  assert(deq);
  if (deq->back == NULL) {
    printf("[empty]\n");
  } else {
    printf("[%d", deq->back->item);
    for (struct llnode * node = deq->back->prev; node != NULL; node = node->prev) {
      printf(",%d", node->item);
    }
    printf("]\n");
  }
}


