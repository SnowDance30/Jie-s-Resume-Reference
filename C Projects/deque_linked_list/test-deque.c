// this is a very simple test for your deque module


#include <assert.h>
#include "deque.h"

int main(void) {
  struct deque *deq = deque_create();
  // deque_print_reverse(deq); /* [empty] */
  deque_print(deq);
  deque_insert_front(1, deq);
  assert(deque_front(deq) == 1);
  assert(deque_back(deq) == 1);
  deque_insert_back(9, deq);
  assert(deque_back(deq) == 9);
  // deque_print(deq); /* [1,9] */
  deque_print(deq);
  assert(deque_remove_front(deq) == 1);
  deque_print(deq);
  assert(deque_back(deq) == 9);
  assert(deque_front(deq) == 9);
  assert(deque_remove_back(deq) == 9);
  assert(deque_is_empty(deq));
  deque_insert_back(1, deq);
  deque_insert_back(2, deq);
  deque_insert_back(3, deq);
  deque_insert_back(4, deq);
  deque_print(deq);
  deque_print_reverse(deq);
  assert(deque_remove_front(deq) == 1);
  assert(deque_remove_front(deq) == 2);
  assert(deque_remove_front(deq) == 3);
  assert(deque_remove_front(deq) == 4);
  assert(deque_is_empty(deq));
  deque_insert_front(1, deq);
  deque_insert_front(2, deq);
  deque_insert_front(3, deq);
  deque_insert_front(4, deq);
  deque_print(deq);
  deque_print_reverse(deq);
  assert(deque_remove_back(deq) == 1);
  assert(deque_remove_back(deq) == 2);
  assert(deque_remove_back(deq) == 3);
  assert(deque_remove_back(deq) == 4);
  assert(deque_is_empty(deq));
  deque_insert_front(2, deq);
  deque_insert_front(1, deq);
  deque_insert_back(3, deq);
  deque_insert_back(4, deq);
  deque_print(deq);
  deque_print_reverse(deq);
  assert(deque_remove_back(deq) == 4);
  assert(deque_remove_front(deq) == 1);
  assert(deque_remove_back(deq) == 3);
  assert(deque_remove_front(deq) == 2);
  assert(deque_is_empty(deq));
  deque_destroy(deq);
}
