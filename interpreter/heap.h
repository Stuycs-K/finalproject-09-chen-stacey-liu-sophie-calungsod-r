#ifndef HEAP
#define HEAP

#include "stack.h"

#define MAX_HEAP_SIZE 100

typedef struct {
  int ary[MAX_HEAP_SIZE];
} Heap;

void store(Heap *heap, Stack *stack);
void retrieve(Heap *heap, Stack *stack);

/* dev */
void print_heap(Heap *heap);

#endif