#include <stdio.h>
#include "stack_test.h"
#include "heap_test.h"

/* Store in heap */
void store(Heap *heap, Stack *stack) {
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