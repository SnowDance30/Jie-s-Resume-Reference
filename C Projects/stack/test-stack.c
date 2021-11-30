// This is a very simple test for your stack module

#include <assert.h>
#include "stack.h"

int main(void) {
  struct stack *s = stack_create();
  stack_push(42, s);
  stack_push(12, s);
  assert(stack_top(s) == 12);
  assert(stack_pop(s) == 12);
  assert(stack_top(s) == 42);
  assert(stack_pop(s) == 42);
  assert(stack_is_empty(s));         
  stack_destroy(s);
}
