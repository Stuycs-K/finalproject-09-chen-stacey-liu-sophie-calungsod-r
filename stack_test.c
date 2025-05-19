#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef struct {
  int ary[MAX_STACK_SIZE];
  int top;
} Stack;

void init(Stack *stack) {
  stack->top = -1;
}

/*Returns 1 if the stack is empty, 0 if not*/
int isEmpty(Stack *stack) {
  return (stack->top == -1);
}

int isFull(Stack *stack) {
  return stack->top == MAX_STACK_SIZE - 1;
}

/*Push number n onto stack*/
void push(Stack *stack, int n) {
  if (isFull(stack)) {
    perror(":(");
    return;
  }
  stack->top++;
  stack->ary[stack->top] = n;
}

/*Duplicate top item on stack*/
void duplicate(Stack *stack) {
  if (isFull(stack) || isEmpty(stack)) {
    perror(":(");
    return;
  }
  stack->top++;
  stack->ary[stack->top] = stack->ary[stack->top-1];
}

/*Swap the top 2 items on stack*/
void swap(Stack *stack) {
  if (isEmpty(stack)) {
    perror(":(");
    return;
  }
  int temp = stack->ary[stack->top];
  stack->ary[stack->top] = stack->ary[stack->top-1];
  stack->ary[stack->top-1] = temp;
}

/*Discard top item on stack*/
void discard(Stack *stack) {
  if (isEmpty(stack)) {
    perror(":(");
    return;
  }
  stack->top--;
}

/*Copy nth item on the stack to top of stack*/
void copy(Stack *stack, int n) {
  if (isFull(stack) || isEmpty(stack)) {
    perror(":(");
    return;
  }
  stack->top++;
  stack->ary[stack->top] = stack->ary[n];
}

/*Slide (pop and discard) n items off the stack, keeping top item*/
void slide(Stack *stack, int n) {
  if (isEmpty(stack)) {
    perror(":(");
    return;
  }
  stack->ary[0] = stack->ary[stack->top];
  stack->top = 0;
}

int main() {
}
