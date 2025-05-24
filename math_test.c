#include <stdio.h>
#include "stack_test.h"

/* 
-> second number popper [operator] first number popped
-> Returns an error if less than 2 items in stack
*/

/* Pushes the sum of the 1st value popped and 2nd value popped to stack */
void add(Stack *stack) {
  if (stack->top < 0) {
    perror("Insufficient number of items in stack");
    return;
  }
  push(stack, (pop(stack) + pop(stack)));
}

/* Pushes the difference of the 2nd value popped and 1st value popped to stack */
void subtract(Stack *stack) {
  if (stack->top < 0) {
    perror("Insufficient number of items in stack");
    return;
  }
  int first_pop = pop(stack);
  push(stack, (pop(stack) - first_pop));
}

/* Pushes the product of the 1st value popped and 2nd value popped to stack */
void multiply(Stack *stack) {
  if (stack->top < 0) {
    perror("Insufficient number of items in stack");
    return;
  }
  push(stack, (pop(stack) * pop(stack)));
}

/* Pushes the quotient of the 2nd value popped and 1st value popped to stack.
 * Returns an error if the 1st value popped is 0
 */
void divide(Stack *stack) {
  if (stack->top < 0) {
    perror("Insufficient number of items in stack");
    return;
  }
  int first_pop = pop(stack);
  int second_pop = pop(stack);
  if (first_pop == 0) {
    perror("Error: unable to divide by 0");
    return;
  }
  push(stack, (second_pop / first_pop));
}

/* Pushes the remainder of the 2nd value popped and 1st value popped to stack 
 * Returns an error if the 1st value popped is 0 
 */
void modulo(Stack *stack) {
  if (stack->top < 0) {
    perror("Insufficient number of items in stack");
    return;
  }
  int first_pop = pop(stack);
  int second_pop = pop(stack);
  if (first_pop == 0) {
    perror("Error: unable to mod 0");
    return;
  }
  push(stack, (second_pop % first_pop));
}
