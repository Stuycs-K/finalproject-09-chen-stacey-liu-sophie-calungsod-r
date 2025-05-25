#include <stdio.h>
#include "stack.h"
#include "heap.h"

/* Store in heap */
void store(Heap *heap, Stack *stack) {
  int value = pop(stack);
  int address = pop(stack);
  heap->ary[address] = value;
}

/* Retrieve from heap */
void retrieve(Heap *heap, Stack *stack) {
  int address = pop(stack);
  int value = heap->ary[address];
  push(stack, value);
}

/* Print full heap. For dev purposes */
void print_heap(Heap *heap) {
  printf("[");
  for (int i = 0; i < 10; i++) {
    printf("%d, ", heap->ary[i]);
  }
  printf("]\n");
}