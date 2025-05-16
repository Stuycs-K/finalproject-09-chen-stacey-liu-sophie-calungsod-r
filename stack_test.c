#include <stdio.h>

#define MAX_STACK_SIZE 100

struct {
  int ary[MAX_STACK_SIZE];
  int top = -1;
} Stack;

void init(Stack *stack) {

}

int isEmpty(Stack *stack) {
  return stack->top == -1;
}

int isFull(Stack *stack) {
  return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, int n) {
  if (isFull) {
    perror(":(");
    return 0;
  }
  top++;
  stack->ary[stack->top] = n;
}

void duplicate(Stack *stack) {
  if (isFull || isEmpty) {
    perror(":(");
    return 0;
  }
  top++;
  stack->ary[stack->top] = stack->ary[stack->top--];
}

int main() {
}
