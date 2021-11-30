// The module shows the implementation in "queue.h" file of stack ADT.


#include "stack.h"
#include "deque.h"
#include <stdlib.h>
#include <assert.h>


// do not modify, these are all the fields you need for wrapper
struct stack {
  struct deque *deq; 
};


// See "stack.h" file for detail documentation.
struct stack *stack_create(void) {
  struct stack *s = malloc(sizeof(struct stack));
  s->deq = deque_create();
  return s;
}


// See "stack.h" file for detail documentation.
void stack_destroy(struct stack *s) {
  assert(s);
  deque_destroy(s->deq);
  free(s);
}


// See "stack.h" file for detail documentation.
bool stack_is_empty(const struct stack *s) {
  assert(s);
  return deque_is_empty(s->deq);
}


// See "stack.h" file for detail documentation.
void stack_push(int item, struct stack *s) {
  assert(s);
  deque_insert_back(item, s->deq);
}


// See "stack.h" file for detail documentation.
int stack_top(const struct stack *s) {
  assert(s);
  return deque_back(s->deq);
}


// See "stack.h" file for detail documentation.
int stack_pop(struct stack *s) {
  assert(s);
  return deque_remove_back(s->deq);
}


