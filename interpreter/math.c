#include <stdio.h>
#include "stack.h"

/* 
-> second number popped [operator] first number popped
-> Returns an error if less than 2 items in stack
*/

/* Pushes the sum of the 1st value popped and 2nd value popped to stack */
void add(Stack *stack) {
  if (isFull(stack)) {
    perror("Math Error: Stack is full");
    return;
  }
  if (stack->top < 1) {
    perror("Math Error: Insufficient number of items in stack");
    return;
  }
  push(stack, (pop(stack) + pop(stack)));
}

/* Pushes the difference of the 2nd value popped and 1st value popped to stack */
void subtract(Stack *stack) {
  if (isFull(stack)) {
    perror("Math Error: Stack is full");
    return;
  }
  if (stack->top < 1) {
    perror("Math Error: Insufficient number of items in stack");
    return;
  }
  int first_pop = pop(stack);
  push(stack, (pop(stack) - first_pop));
}

/* Pushes the product of the 1st value popped and 2nd value popped to stack */
void multiply(Stack *stack) {
  if (isFull(stack)) {
    perror("Math Error: Stack is full");
    return;
  }
  if (stack->top < 1) {
    perror("Math Error: Insufficient number of items in stack");
    return;
  }
  push(stack, (pop(stack) * pop(stack)));
}

/* Pushes the quotient of the 2nd value popped and 1st value popped to stack */
void divide(Stack *stack) {
  if (isFull(stack)) {
    perror("Math Error: Stack is full");
    return;
  }
  if (stack->top < 1) {
    perror("Math Error: Insufficient number of items in stack");
    return;
  }
  int first_pop = pop(stack);
  int second_pop = pop(stack);
  if (first_pop == 0) {
    perror("Math Error: Unable to divide by 0");
    return;
  }
  push(stack, (second_pop / first_pop));
}

/* Pushes the remainder of the 2nd value popped and 1st value popped to stack */
void modulo(Stack *stack) {
  if (isFull(stack)) {
    perror("Math Error: Stack is full");
    return;
  }
  if (stack->top < 1) {
    perror("Math Error: Insufficient number of items in stack");
    return;
  }
  int first_pop = pop(stack);
  int second_pop = pop(stack);
  if (first_pop == 0) {
    perror("Math Error: Unable to mod 0");
    return;
  }
  push(stack, (second_pop % first_pop));
}
