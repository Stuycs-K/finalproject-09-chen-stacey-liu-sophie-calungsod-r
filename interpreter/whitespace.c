#include "whitespace.h"
#include "stack.h"
#include "heap.h"
#include "math.h"
#include "flowcontrol.h"
#include "io.h"

Stack stack;
Heap heap;

int main(int argc, char *argv[]){
  init(&stack);
  if (argc<=1){
    printf("Use either option '-p' to print the translated Whitespace or '-r' to run the translated command.\n");
  }
  if (argc>2 && strcmp(argv[1],"-p")==0){ // first argument is 'p', print the translated
    char * fileName = argv[2];
    char * stringOf = readFile(fileName);
    printReadable(stringOf); // should print in N,S,T
  }
  if (argc>2 && strcmp(argv[1],"-r")==0){ // first argument is 'r', runs the translated command
    char * fileName = argv[2];
    char * stringOf = readFile(fileName);
    runProgram(stringOf);
  }
}

void runProgram(char *code){ // handles running commands sequentially
  char *p = code; // pointer at the beginning

  while(*p!='\0'){ // while it's not at the end
    int command = whichFunc(&p);
    if(command<0){
      printf("Error %d: %s\n", errno, strerror(errno));
    }
  }
}

// prints whitespace code in readable [Tab][LF][Space] format
void printReadable(char * str){
  for (int i = 0; i<strlen(str); i++){
    if (str[i] == '\t') printf("[Tab]");
    else if (str[i] == '\n') printf("[LF]\n");
    else if (str[i] == ' ') printf("[Space]");
    else printf(" ");
  }
}


/* goes through code and returns a labelInfo array with all labels 
in the code marks returnLabel as well (the subroutine) */
struct labelInfo * retrieveLabels(char * ptr, struct labelInfo * returnLabel){
  struct labelInfo * label_ary = (struct labelInfo *)malloc(ARRAY_SIZE*sizeof(struct labelInfo)); // keeps track of labels & their pointers
  struct labelInfo * labelAry_ptr = label_ary;

  while (*ptr != '\0'){
    if ((*ptr=='\t' && *(ptr+1)==' ') || (*ptr=='\t' && *(ptr+1)=='\n')) ptr += 4;
    else if (*ptr=='\t' && *(ptr+1)=='\t') ptr += 3;
    else if (*ptr == ' '){
      if ((*(ptr+1)=='\n' && *(ptr+2)==' ') || (*(ptr+1)=='\n' && *(ptr+2)=='\t') || (*(ptr+1)=='\n' && *(ptr+2)=='\n')) ptr += 3;
      else {
        while (*ptr != '\n') ptr++;
        ptr++;
      }
    }
    else if (*ptr == '\n'){
      if (*(ptr+1)==' ' && *(ptr+2)==' '){ // mark the label
        ptr+=3;
        char * label = findLabel(ptr);
        ptr += strlen(label)+1;
        markLoc(labelAry_ptr, label, ptr);
        labelAry_ptr++;
      }
      else if (*(ptr+1)=='\t' && *(ptr+2)=='\n') ptr += 3;
      else if (*(ptr+1)=='\n' && *(ptr+2)=='\n') return label_ary;
      else if (*(ptr+1)==' ' && *(ptr+2)=='\t') {
        ptr+= 3;
        char * label = findLabel(ptr);
        ptr += strlen(label)+1;
        markLoc(returnLabel, label, ptr);
      }
      else if ((*(ptr+1)==' ' && *(ptr+2)=='\n') ||
               (*(ptr+1)=='\t' && *(ptr+2)==' ') ||
               (*(ptr+1)=='\t' && *(ptr+2)=='\t')) {
                 ptr += 3;
                 ptr += strlen(findLabel(ptr)) + 1;
               }
    }
  }
  return label_ary;
}

// turns the file into a string
char * readFile(char* fileName){
  int file = open(fileName, O_RDONLY , 0);
  if(file == -1){
    // prints "Error #: Error message here"
    printf("Error %d: %s\n", errno, strerror(errno));
  }

  char* buff = malloc(1024*4); // make files later, see if we need more
  if (buff==NULL){
    perror("didn't malloc buff correctly");
  }
  int len = 0; // used to go through the buffer

  char space;
  while(read(file,&space,1)==1){ // while there's something to read
    if(space==' ' || space=='\n' || space=='\t'){
      buff[len]=space;
      len++;
    }
  }

  buff[len] = '\0';
  close(file);
    return buff;
  }


int whichFunc(char** p){ // points to where we are in the string
  char *ptr = *p;
  char * labelPtr = *p;

  struct labelInfo * returnLabel = (struct labelInfo *)malloc(sizeof(struct labelInfo)); // for flow control subroutine
  struct labelInfo * label_ary = retrieveLabels(labelPtr, returnLabel); // keeps track of labels & their pointers

  // MATH
  if (*ptr=='\t' && *(ptr+1)==' '){ // [TAB][SPACE] beginning indicates math
    if (*(ptr+2)==' ' && *(ptr+3)==' '){ // [SPACE][SPACE] addition
      // call addition function
      add(&stack);
    }
    if (*(ptr+2)==' ' && *(ptr+3)=='\t'){ // [SPACE][TAB] subtraction
      // call subtraction function
      subtract(&stack);
    }
    if (*(ptr+2)==' ' && *(ptr+3)=='\n'){ // [SPACE][LINEFEED] multiplication
      // call multiplication function
      multiply(&stack);
    }
    if (*(ptr+2)=='\t' && *(ptr+3)==' '){ // [TAB][SPACE] int division
      // call int division function
      divide(&stack);
    }
    if (*(ptr+2)=='\t' && *(ptr+3)=='\t'){ // [TAB][TAB] modulo
      // call modulo function
      modulo(&stack);
    }
    ptr+=4;
    *p = ptr;
    return 1;
  }
  // input/output
  else if (*ptr=='\t' && *(ptr+1)=='\n'){
    if (*(ptr+2)=='\t' && *(ptr+3)==' '){
      // call 1st IO function
      input_char(&stack, &heap);
    }
    if (*(ptr+2)=='\t' && *(ptr+3)=='\t'){
      // call 2nd IO function
      input_num(&stack, &heap);
    }
    if (*(ptr+2)==' ' && *(ptr+3)==' '){
      // call 3rd IO function
      output_char(&stack);
    }
    if (*(ptr+2)==' ' && *(ptr+3)=='\t'){
      // call 4th IO function
      output_num(&stack);
    }
    ptr+=4;
    *p = ptr;
    return 1;
  }
  // stack manipulation
  else if (*ptr==' '){
    if (*(ptr+1)==' '){
      // push number onto stack
      ptr+= 2;
      int numLen = 0;
      push(&stack, findNumber(ptr, &numLen));
      ptr += numLen;
    }
    else if (*(ptr+1)=='\n' && *(ptr+2)==' '){
      // duplicate top item on stack
      duplicate(&stack);
      ptr+=3;
    }
    else if (*(ptr+1)=='\n' && *(ptr+2)=='\t'){
      // swap 2 top items on stack
      swap(&stack);
      ptr+=3;
    }
    else if (*(ptr+1)=='\n' && *(ptr+2)=='\n'){
      // discard top item on stack
      discard(&stack);
      ptr+=3;
    }
    else if (*(ptr+1)==' '){
      // Copy nth item on the stack onto top of stack
      ptr+= 3;
      int numLen = 0;
      copy(&stack, findNumber(ptr, &numLen));
      ptr += numLen;
    }
    else if (*(ptr+1)=='\n'){
      // Slide n items off the stack, keeping top item
      ptr+= 3;
      int numLen = 0;
      slide(&stack, findNumber(ptr, &numLen));
      ptr += numLen;
    }
    *p = ptr;
    return 1;
  }
  // heap access
  else if (*ptr=='\t' && *(ptr+1)=='\t'){
    if (*(ptr+2)==' '){
      // store in heap
      store(&heap, &stack);
    }
    if (*(ptr+2)=='\t'){
      // retrieve from heap
      retrieve(&heap, &stack);
    }
    ptr+=3;
    *p = ptr;
    return 1;
  }
  // flow control
  else if (*ptr=='\n'){ // [LINEFEED] indicates flow control
    if (*(ptr+1)==' ' && *(ptr+2)==' '){ // [SPACE][SPACE][LABEL]
      // Mark a location in program (already done in retrieveLabels)
      ptr+=3;
      char * label = findLabel(ptr);
      ptr += strlen(label)+1; // move pointer to code after the label
    }
    else if (*(ptr+1)==' ' && *(ptr+2)=='\t'){ // [SPACE][TAB][LABEL]
      // Call a subroutine
      ptr+=3;
      char * label = findLabel(ptr);
      ptr += strlen(label)+1;
      unCondJump(label, label_ary, &ptr);
    }
    else if (*(ptr+1)==' ' && *(ptr+2)=='\n'){ // [SPACE][LINEFEED][LABEL]
      // Jump unconditionally to a label
      ptr+=3;
      char * label = findLabel(ptr);
      unCondJump(label, label_ary, &ptr);
    }
    else if (*(ptr+1)=='\t' && *(ptr+2)==' '){ // [TAB][SPACE][LABEL]
      // Jump to a label if the top of the stack is zero
      ptr+=3;
      char * label = findLabel(ptr);
      if (pop(&stack) == 0) unCondJump(label, label_ary, &ptr);
      else ptr += strlen(label)+1;
    }
    else if (*(ptr+1)=='\t' && *(ptr+2)=='\t'){ // [TAB][TAB][LABEL]
      // Jump to label if the top of the stack is negative
      ptr+=3;
      char * label = findLabel(ptr);
      if (pop(&stack) < 0) unCondJump(label, label_ary, &ptr);
      else ptr += strlen(label)+1;
    }
    else if (*(ptr+1)=='\t' && *(ptr+2)=='\n'){ // [TAB][LINEFEED]
      // End subroutine & transfer control back to caller
      ptr = returnLabel -> label_ptr;
    }
    else if (*(ptr+1)=='\n' && *(ptr+2)=='\n'){ // [LINEFEED][LINEFEED]
      // End program
      **p = '\0';
      return 1;
      // ptr+=2;
    }
    *p = ptr;
    return 1;
  }

  *p = ptr;
  return -1; // nothing worked

}




// might not need this here, was just used for testing in main
int findNumber(char* str, int * numLen){
  int num = 0;
  int sign = 1;
  int n = 0; // keep track of how many spaces we shifted the pointer
  char * ptr = str;
  if (*ptr == '\t') sign=-1;
  n++;
  while (*(ptr+n) != '\n' && *(ptr+n) != '\0'){
    if (*(ptr+n) == ' '){
      num = num << 1;
    }
    else if (*(ptr+n) == '\t'){
      num = num << 1;
      num++;
    }
    n++;
  }
  *numLen = n+1;
  return sign*num;
}
