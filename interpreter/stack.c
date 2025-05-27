#include <stdio.h>
#include "stack.h"

/* Set stack length to 0 */
void init(Stack *stack) {
  stack->top = -1;
}

/* Returns 1 if the stack is empty, 0 if not */
int isEmpty(Stack *stack) {
  return (stack->top == -1);
}

/* Returns 1 if the stack is full, 0 if not */
int isFull(Stack *stack) {
  return stack->top == MAX_STACK_SIZE - 1;
}

/* Push number n onto stack */
void push(Stack *stack, int n) {
  if (isFull(stack)) {
    perror("Stack Error: Stack is full");
    return;
  }
  stack->top++;
  stack->ary[stack->top] = n;
}

/* Duplicate top item on stack */
void duplicate(Stack *stack) {
  if (isFull(stack)) {
    perror("Stack Error: Stack is full");
    return;
  }
  if (isEmpty(stack)) {
    perror("Stack Error: Stack is empty");
    return;
  }
  stack->top++;
  stack->ary[stack->top] = stack->ary[stack->top-1];
}

/* Swap the top 2 items on stack */
void swap(Stack *stack) {
  if (stack->top < 1) {
    perror("Stack Error: Insufficient number of items in stack");
    return;
  }
  int temp = stack->ary[stack->top];
  stack->ary[stack->top] = stack->ary[stack->top-1];
  stack->ary[stack->top-1] = temp;
}

/* Discard top item on stack */
void discard(Stack *stack) {
  if (isEmpty(stack)) {
    perror("Stack Error: Stack is empty");
    return;
  }
  stack->top--;
}

/* Copy nth item on the stack to top of stack */
void copy(Stack *stack, int n) {
  if (isFull(stack)) {
    perror("Stack Error: Stack is full");
    return;
  }
  if (stack->top < n-1) {
    perror("Stack Error: Item at given index does not exist in stack");
    return;
  }
  stack->top++;
  stack->ary[stack->top] = stack->ary[n-1];
}

/* Slide (pop and discard) n items below the top item off the stack, keeping top item 
 * example: stack={1, 2, 3, 4}, n=2 --> stack={1, 4}
 */
void slide(Stack *stack, int n) {
  if (isEmpty(stack)) {
    perror("Stack Error: Stack is empty");
    return;
  }
  if (n >= stack->top) { //only top item remains if n >= (the amt of items in stack - 1)
    stack->ary[0] = stack->ary[stack->top];
    stack->top = 0;
  }
  else {
    stack->ary[stack->top - n] = stack->ary[stack->top];
    stack->top = (stack->top - n);
  }
}

/* Pop and return the top item */
int pop(Stack *stack) {
  if (isEmpty(stack)) {
    perror("Stack Error: Stack is empty");
    return 0;
  }
  stack->top--;
  return stack->ary[stack->top+1];
}

/* Print full stack. For dev purposes */
void print(Stack *stack) {
  printf("{");
  for (int i = 0; i <= stack->top; i++) {
    printf("%d, ", stack->ary[i]);
  }
  printf("}\n");
}
