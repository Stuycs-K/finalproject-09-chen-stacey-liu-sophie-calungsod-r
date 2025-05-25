#ifndef STACK
#define STACK

#define MAX_STACK_SIZE 100

typedef struct {
  int ary[MAX_STACK_SIZE];
  int top;
} Stack;

void init(Stack *stack);

int isEmpty(Stack *stack);
int isFull(Stack *stack);

void push(Stack *stack, int n);
void duplicate(Stack *stack);
void swap(Stack *stack);
void discard(Stack *stack);
void copy(Stack *stack, int n);
void slide(Stack *stack, int n);
int pop(Stack *stack);

/* dev */
void print(Stack *stack);

#endif
