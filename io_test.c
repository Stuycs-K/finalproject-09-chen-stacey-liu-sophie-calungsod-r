/* for input/output commands */
#include <stdio.h>
#include "stack_test.h"
#include "heap_test.h"

//should we add a print statement asking for input?

/* Takes user input and inputs it as an ASCII character to a heap.
 * Uses first popped item from stack for the heap address
 */
void input_char(Stack *stack, Heap *heap) {
    //get user input
    char value;
    char input[256];
    fgets(input, 255, stdin);
    //printf("input a character: ");
    sscanf(input, "%c", &value);

    //store input to heap
    if (isEmpty(stack)) {
        perror("Input Error: Stack is empty");
        return;
    }
    int address = pop(stack);
    heap->ary[address] = value;
}

/* Takes user input and inputs it as a number to a heap.
 * Uses first popped item from stack for the heap address
 */
void input_num(Stack *stack, Heap *heap) {
    //get user input
    int value;
    char input[256];
    fgets(input, 255, stdin);
    //printf("input a number: ");
    sscanf(input, "%d", &value);
    
    //store input to heap
    if (isEmpty(stack)) {
        perror("Input Error: Stack is empty");
        return;
    }
    int address = pop(stack);
    heap->ary[address] = value;
}

/* Outputs top of stack as an ASCII character */
void output_char(Stack *stack) {
    if (isEmpty(stack)) {
        perror("Output Error: Stack is empty");
        return;
    }
    fprintf(stdout, "%c", pop(stack));
    fflush(stdout);
}

/* Outputs top of stack as a number */
void output_num(Stack *stack) {
    if (isEmpty(stack)) {
        perror("Output Error: Stack is empty");
        return;
    }
    fprintf(stdout, "%d", pop(stack));
    fflush(stdout);
}