#include <stdio.h>
#include "stack_test.h"

/*Returns the sum of the 1st value popped and 2nd value popped*/
int add(Stack *stack) {
  if (stack->top < 0) {
    perror(":(");
    return NULL;
  }
  return (pop(stack) + pop(stack));
}

/*Returns the difference of the 1st value popped and 2nd value popped*/
int subtract(Stack *stack) {
  if (stack->top < 0) {
    perror(":(");
    return NULL;
  }
  return (pop(stack) - pop(stack));
}

/*Returns the product of the 1st value popped and 2nd value popped*/
int multiply(Stack *stack) {
  if (stack->top < 0) {
    perror(":(");
    return NULL;
  }
  return (pop(stack) * pop(stack));
}
/*Returns the quotient of the 1st value popped and 2nd value popped*/
int divide(Stack *stack) {
  if (stack->top < 0) {
    perror(":(");
    return NULL;
  }
  return (pop(stack) / pop(stack));
}

/*Returns the remainder of the 1st value popped and 2nd value popped*/
int modulo(Stack *stack) {
  if (stack->top < 0) {
    perror(":(");
    return NULL;
  }
  return (pop(stack) % pop(stack));
}
