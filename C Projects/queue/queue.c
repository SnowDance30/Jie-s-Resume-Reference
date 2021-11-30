// The module shows the implementation in "queue.h" file of queue ADT.


#include "queue.h"
#include "deque.h"
#include <stdlib.h>
#include <assert.h>


// do not modify, these are all the fields you need for wrapper
struct queue {
  struct deque *deq;
};


// See "queue.h" file for detail documentation.
struct queue *queue_create(void) {
  struct queue *que = malloc(sizeof(struct queue));
  que->deq = deque_create();
  return que;
}


// See "queue.h" file for detail documentation.
void queue_destroy(struct queue *q) {
  assert(q);
  deque_destroy(q->deq);
  free(q);
}


// See "queue.h" file for detail documentation.
bool queue_is_empty(const struct queue *q) {
  assert(q);
  return deque_is_empty(q->deq);
} 


// See "queue.h" file for detail documentation.
void queue_add_back(int item, struct queue *q) {
  assert(q);
  deque_insert_back(item, q->deq);
}


// See "queue.h" file for detail documentation.
int queue_front(const struct queue *q) {
  assert(q);
  return deque_front(q->deq);
}


// See "queue.h" file for detail documentation.
int queue_remove_front(struct queue *q) {
  assert(q);
  return deque_remove_front(q->deq);
}


