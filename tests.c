#include <stdio.h>
#include "stack_test.h"
#include "math_test.h"

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

  printf("%d\n", add(&stack));
  print(&stack);
  printf("%d\n", subtract(&stack));
  printf("%d\n", divide(&stack));
  printf("%d\n", multiply(&stack));
  printf("%d\n", modulo(&stack));

  return 0;
}
