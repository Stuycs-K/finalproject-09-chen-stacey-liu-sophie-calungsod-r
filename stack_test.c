#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef struct {
  int ary[MAX_STACK_SIZE];
  int top;
} Stack;

/*Set stack length to 0*/
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

/*Swap the top 2 items on stack. If stack size is less than 2, return error*/
void swap(Stack *stack) {
  if (stack->top < 1) {
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
  if (isFull(stack) || stack->top < n-1) {
    perror(":(");
    return;
  }
  stack->top++;
  stack->ary[stack->top] = stack->ary[n-1];
}

/*Slide (pop and discard) n items off the stack, keeping top item*/
void slide(Stack *stack, int n) {
  if (isEmpty(stack)) {
    perror(":(");
    return;
  }
  if (n >= (stack->top + 1)) {
    stack->ary[0] = stack->ary[stack->top];
    stack->top = 0;
  }
  else {
    int i = 0;
    for (int j = n; j <= stack->top; j++) {
      stack->ary[i] = stack->ary[j];
      i++;
    }
    stack->top = i-1;
  }
}

/*Pop and return the top item*/
int pop(Stack *stack) {
  if (isEmpty(stack)) {
    perror(":(");
    return 0;
  }
  stack->top--;
  return stack->ary[stack->top+1];
}

/*Print full stack. For dev purposes*/
void print(Stack *stack) {
  printf("{");
  for (int i = 0; i <= stack->top; i++) {
    printf("%d, ", stack->ary[i]);
  }
  printf("}\n");
}

int main() {
  Stack stack;
  init(&stack);

  push(&stack, 3);
  print(&stack);

  push(&stack, 5);
  print(&stack);

  push(&stack, 2);
  print(&stack);

  push(&stack, 8);
  print(&stack);

  swap(&stack);
  print(&stack);

  duplicate(&stack);
  print(&stack);

  discard(&stack);
  print(&stack);

  copy(&stack, 2);
  print(&stack);

  slide(&stack, 2);
  print(&stack);

  printf("%d\n", pop(&stack));
  print(&stack);

  return 0;
}
