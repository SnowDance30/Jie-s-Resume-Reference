// This is a very simple test for your queue module

#include <assert.h>
#include "queue.h"

int main(void) {
  struct queue *q = queue_create();
  queue_add_back(42, q);
  queue_add_back(12, q);
  assert(queue_front(q) == 42);
  assert(queue_remove_front(q) == 42);
  assert(queue_front(q) == 12);
  assert(queue_remove_front(q) == 12);
  assert(queue_is_empty(q));
  queue_destroy(q);
}
