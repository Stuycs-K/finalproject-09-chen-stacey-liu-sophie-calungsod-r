#include "numbertest.h"
#define ARRAY_SIZE 100
int main(){
  char* test = " \t  \t \t\t\n"; // 75
  char* test2 = "\t\t\t  \t \n"; // -50
  printf("%d\n", findNumber(test));
  printf("%d\n", findNumber(test2));

  // char ** label_ary = malloc(ARRAY_SIZE);
  // char * labelString = "\n  \t\n";
  // char * label = "\t\n";
  // markLoc(label_ary, label, &label);

  // code for flow control part of whitespace, reference whichFunc() in whitespace.c
  char * testline = "\n  \t\n"; // placeholder string for now
  char * ptr; // points to where you are in string/Whitespace code
  char ** label_ary; // keeps track of labels & their pointers
  Stack * stack;
  if (*(ptr) == '\n'){ // if IMP is N, aka flow control
    if (*(ptr+1) == ' ' && *(ptr+2) == ' '){ // mark location with the label
      ptr+= 3;
      char * label = findLabel(ptr);
      ptr += strlen(label);
      markLoc(label_ary, label, &(ptr-strlen));
      ptr++; // move pointer to after the /n
    }
    if (*(ptr+1) == ' ' && *(ptr+2) == '\t'){ // call subroutine

    }
    if (*(ptr+1) == ' ' && *(ptr+2) == '\n'){ // jump unconditionally
      ptr+= 3;
      char * label = findLabel(ptr);
      ptr += strlen(label);
      unCondJump(label, label_ary, &ptr);
    }
    if (*(ptr+1) == '\t' && *(ptr+2) == ' '){ // zero jump
      ptr+= 3;
      char * label = findLabel(ptr);
      ptr += strlen(label);
      //NTS[label]
      if (stack->ary[stack->top] == 0) unCondJump(label, label_ary, &ptr);
    }
    if (*(ptr+1) == '\t' && *(ptr+2) == '\t'){ // negative jump
      ptr+= 3;
      char * label = findLabel(ptr);
      ptr += strlen(label);
      //NTT[label]
      if (stack->ary[stack->top] < 0) unCondJump(label, label_ary, &ptr);
    }
    if (*(ptr+1) == '\t' && *(ptr+2) == '\n'){ // end subroutine

    }
    if (*(ptr+1) == '\n' && *(ptr+2) == '\n'){ // end program

    }
  }

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

char * findLabel(char * ptr){
  int strlen = 0;
  while (*ptr != '\n') {
    strlen++;
    ptr++;
  }
  strncpy(label, ptr-strlen, strlen);
  return label;
}

// flow control -- move this to another file eventually
// in the main file, keep a 2d array (label_ary), which stores the labels & the pointer to that label
// each array in label_ary -> [label, address]
void markLoc(char ** label_ary, char* label, char* ptr){
  // NSS[label]
  char[2] subary = {label, ptr};
  *(label_ary) = subary
  //maybe don't have this as a function -> just save pointer + label as pair in array
}

void callSubRoutine(char ** label_ary, char * label, char* ptr){
  // NST[label]
}

void unCondJump(char * label, char ** label_ary, char ** currPtr){
  //NSN[label]
  // currPtr is address of the pointer denoting where we are in the Whitespace code
  // label_ary is the array of labels and their pointers
  // label is the label we jump to
  // loop through label_ary & if label is found, set currPtr(might need to be char **) to the pointer associated with that label
  for (int i = 0; i<ARRAY_SIZE; i++){
    if (!strcmp(label, label_ary[i][0])){
      *currPtr = label_ary[i][1];
      break;
    }
  }
}

void zeroJump(Stack *stack, char * label){
  //NTS[label]
  if (stack->ary[stack->top] == 0) unCondJump(label, label_ary, currPtr);
}
void negJump(Stack *stack, char * label){
  //NTT[label]
  if (stack->ary[stack->top] < 0) unCondJump(stack, label);
}
