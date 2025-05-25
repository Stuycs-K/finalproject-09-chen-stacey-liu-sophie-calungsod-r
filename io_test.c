/* for input/output commands */
#include <stdio.h>
#include "stack_test.h"
#include "heap_test.h"

/* Takes user input and inputs it as an ASCII character to a heap.
 * Uses first popped item from stack for the heap address
 */
void input_char(Stack *stack, Heap *heap) {
    //get user input
    char value;
    char input[256];
    fgets(input, 255, stdin);
    sscanf(input, "%c", value);

    //store input to heap
    int address = pop(stack);
    heap->ary[address] = value;
}

/* Takes user input and inputs it as a number to a heap.
 * Uses first popped item from stack for the heap address
 */
void input_num(Stack *stack, Heap *heap) {
    //get user input
    char value;
    char input[256];
    fgets(input, 255, stdin);
    sscanf(input, "%d", value);
    
    //store input to heap
    int address = pop(stack);
    heap->ary[address] = value;
}

/* Outputs top of stack as an ASCII character */
void output_char(Stack *stack) {
    fprintf(stdout, "%c", pop(stack));
    fflush(stdout);
}

/* Outputs top of stack as a number */
void output_num(Stack *stack) {
    fprintf(stdout, "%d", pop(stack));
    fflush(stdout);
}