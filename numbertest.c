#include "numbertest.h"
#define ARRAY_SIZE 100
int main(){
  char* test = " \t  \t \t\t\n"; // 75
  char* test2 = "\t\t\t  \t \n"; // -50
  printf("%d\n", findNumber(test));
  printf("%d\n", findNumber(test2));

  char ** label_ary = malloc(ARRAY_SIZE);
  char * labelString = "\n  \t\n";
  char * label = "\t\n";
  markLoc(label_ary, label, &label);


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
// in the main file, keep a 2d array (label_ary), which stores the labels & the pointer to that label
// each array in label_ary -> [label, address]
void markLoc(char ** label_ary, char* label, char* ptr){
  // NSS[label]
  char[2] subary = {label, ptr};
  *(label_ary) = subary
  //maybe don't have this as a function -> just save pointer + label as pair in array
}

void callSubRoutine(char * label){
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
  if (stack->ary[stack->top] == 0) unCondJump(stack, label);
}
void negJump(Stack *stack, char * label){
  //NTT[label]
  if (stack->ary[stack->top] < 0) unCondJump(stack, label);
}
