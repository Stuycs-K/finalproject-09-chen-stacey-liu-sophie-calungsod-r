#include <stdio.h>
#include "stack_test.h"
#include "heap_test.h"
#include "math_test.h"
#include "io_test.h"

int main() {
  Stack stack;
  init(&stack);

  push(&stack, 3);
  print(&stack);

  push(&stack, 5);
  print(&stack);

  push(&stack, 2);
  print(&stack);

  push(&stack, 8);
  print(&stack);

  swap(&stack);
  print(&stack);

  duplicate(&stack);
  print(&stack);

  discard(&stack);
  print(&stack);

  copy(&stack, 2);
  print(&stack);

  slide(&stack, 2);
  print(&stack);

  printf("%d\n", pop(&stack));
  print(&stack);

  push(&stack, 3);
  print(&stack);

  push(&stack, 5);
  print(&stack);

  push(&stack, 2);
  print(&stack);

  push(&stack, 8);
  print(&stack);

  push(&stack, 3);
  print(&stack);

  push(&stack, 5);
  print(&stack);

  push(&stack, 2);
  print(&stack);

  push(&stack, 8);
  print(&stack);

  push(&stack, 3);
  print(&stack);

  push(&stack, 5);
  print(&stack);

  push(&stack, 2);
  print(&stack);

  push(&stack, 8);
  print(&stack);

  printf("MATH\n");

  add(&stack);
  print(&stack);

  subtract(&stack);
  print(&stack);

  divide(&stack);
  print(&stack);

  multiply(&stack);
  print(&stack);

  modulo(&stack);
  print(&stack);

  Heap heap;
  print_heap(&heap);

  retrieve(&heap, &stack);
  print(&stack);

  store(&heap, &stack);
  print_heap(&heap);

  store(&heap, &stack);
  pop(&stack);

  retrieve(&heap, &stack);
  
  print_heap(&heap);
  print(&stack);

  output_num(&stack);
  output_num(&stack);
  push(&stack, 72);
  output_char(&stack);

  input_char(&stack, &heap);
  print_heap(&heap);

  push(&stack, 5);
  input_num(&stack, &heap);
  print_heap(&heap);


  return 0;
}
