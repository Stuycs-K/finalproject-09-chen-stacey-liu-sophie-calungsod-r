#include <stdio.h>
#include "stack_test.h"
#include "heap_test.h"

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