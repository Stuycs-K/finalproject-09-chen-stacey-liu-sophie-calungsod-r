#include "numbertest.h"

int main(){
  char* test = " \t  \t \t\t\n";
  char* test2 = "\t\t\t  \t \n";
  printf("%d\n", findNumber(test2));
  return 0;
}

int findNumber(char* str){
  int num = 0;
  int sign = 1;
  char * ptr = str;
  if (*ptr == '\t') sign=-1;
  ptr++;
  while (*ptr != '\n'){
    if (*ptr == ' '){
      num = num << 1;
    }
    else if (*ptr == '\t'){
      num = num << 1;
      num++;
    }
    ptr++;
  }
  return sign*num;
}

// flow control -- move this to another file eventually
void markLoc(char* label){
  // NSS[label]
  // save as pointer?
  //maybe don't have this as a function -> just save pointer + label as pair in array
}

void callSubRoute(){
  // NST[label]
}

void unCondJump(Stack *stack){
  //NSN[label]
}

void zeroJump(Stack *stack, char * label){
  //NTS[label]
  if (stack->ary[stack->top] == 0) unCondJump(stack, label);
}
void negJump(){
  //NTT[label]
  if (stack->ary[stack->top] < 0) unCondJump(stack, label);
}
