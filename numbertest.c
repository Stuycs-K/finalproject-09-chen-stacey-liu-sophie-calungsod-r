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
  // save as pointer? char **
  //maybe don't have this as a function -> just save pointer + label as pair in array
}

void callSubRoutine(char * label){
  // NST[label]
}

void unCondJump(char * label){
  //NSN[label]
}

void zeroJump(Stack *stack, char * label){
  //NTS[label]
  if (stack->ary[stack->top] == 0) unCondJump(stack, label);
}
void negJump(Stack *stack, char * label){
  //NTT[label]
  if (stack->ary[stack->top] < 0) unCondJump(stack, label);
}
