#include <stdio.h>
#include "stack.h"
#include "heap.h"

/* Store in heap */
void store(Heap *heap, Stack *stack) {
  if (stack->top < 1) {
    perror("Heap Error: Insufficient number of items in stack");
    return;
  }
  int value = pop(stack);
  int address = pop(stack);
  if (address >= MAX_HEAP_SIZE || address < 0) {
    perror("Heap Error: Invalid address");
    return;
  }
  heap->ary[address] = value;
}

/* Retrieve from heap */
void retrieve(Heap *heap, Stack *stack) {
  if (isFull(stack)) {
    perror("Heap Error: Stack is full");
    return;
  }
  if (isEmpty(stack)) {
    perror("Heap Error: Stack is empty");
    return;
  }
  int address = pop(stack);
  if (address >= MAX_HEAP_SIZE || address < 0) {
    perror("Heap Error: Invalid address");
    return;
  }
  int value = heap->ary[address];
  push(stack, value);
}

/* Print start of heap. For dev purposes */
void print_heap(Heap *heap) {
  printf("[");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", heap->ary[i]);
  }
  printf("]\n");
}