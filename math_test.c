#include <stdio.h>
#include "stack_test.h"

// second number popper [operator] first number popped
// do we push the found value to the stack????? 

/* Returns the sum of the 1st value popped and 2nd value popped.
 * Returns 0 if stack has less than 2 items.
 */
int add(Stack *stack) {
  if (stack->top < 0) {
    perror(":(");
    return 0;
  }
  return (pop(stack) + pop(stack));
}

/* Returns the difference of the 2nd value popped and 1st value popped.
 * Returns 0 if stack has less than 2 items.
 */
int subtract(Stack *stack) {
  if (stack->top < 0) {
    perror(":(");
    return 0;
  }
  int first_pop = pop(stack);
  return (pop(stack) - first_pop);
}

/* Returns the product of the 1st value popped and 2nd value popped.
 * Returns 0 if stack has less than 2 items.
 */
int multiply(Stack *stack) {
  if (stack->top < 0) {
    perror(":(");
    return 0;
  }
  return (pop(stack) * pop(stack));
}
/* Returns the quotient of the 2nd value popped and 1st value popped.
 * Returns 0 if stack has less than 2 items.
 */
int divide(Stack *stack) {
  if (stack->top < 0) {
    perror(":(");
    return 0;
  }
  return (1 / (pop(stack) / pop(stack)));
}

/* Returns the remainder of the 2nd value popped and 1st value popped.
 * Returns 0 if stack has less than 2 items.
 */
int modulo(Stack *stack) {
  if (stack->top < 0) {
    perror(":(");
    return 0;
  }
  int first_pop = pop(stack);
  return (pop(stack) % first_pop);
}
