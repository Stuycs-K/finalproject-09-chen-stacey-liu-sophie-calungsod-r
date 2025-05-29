/* for input/output commands */
#include <stdio.h>
#include "stack.h"
#include "heap.h"

/* Takes user input and inputs the first character as an ASCII character to a heap.
 * Uses first popped item from stack for the heap address
 */
void input_char(Stack *stack, Heap *heap) {
    //get user input
    char value;
    char input[3];
    printf("/Input a character/: ");
    fgets(input, 2, stdin);
    sscanf(input, "%c", &value);
    fflush(stdin);

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
    printf("/Input a number/: ");
    fgets(input, 255, stdin);
    sscanf(input, "%d", &value);
    fflush(stdin);
    
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
