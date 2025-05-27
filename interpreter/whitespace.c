#include "whitespace.h"
#include "stack.h"
#include "heap.h"
#include "math.h"
#include "io.h"

Stack stack;
Heap heap;

int main(int argc, char const *argv[]){
  init(&stack);

  if (argc<=1){
    printf("\nUse either option '-p' to print the translated Whitespace or '-r' to run the translated command.");
  }
  if (argc>1 && strcmp(argv[1],"-p")==0){ // first argument is 'p', print the translated
    /*char translated[] = "hi"; // replace with function call
    printf("%s", translated);*/

    char * stringOf = readFile("hw.txt");
    printf("%s", stringOf); // prints empty space obviously... make a func to actually print
    runProgram(stringOf);
    //printf("here is the string from the file: %s\n",stringOf);
    //printf("translated number: %d",findNumber(stringOf));
  }
  if (argc>1 && strcmp(argv[1],"-r")==0){ // first argument is 'r', runs the translated command
    // uses function on a string and then calls execvp successfully
<<<<<<< HEAD:whitespace.c
    /*char * args[1024*4]; // change later
    char line[] = "echo 'Hello World'"; // this line should come from 
=======
    char * args[1024*4]; // change later
    char line[] = "echo 'Hello World'"; // this line should come from
>>>>>>> f3e125f5c24977f81d1a137d5a1553cc3c2a074c:interpreter/whitespace.c
    parse_args(line, args); // feeds in lines, returns args
    execvp(args[0], args);*/

    char * stringOf = readFile("hw.txt");
    runProgram(stringOf);
  }
}

void runProgram(char *code){ // handles running commands sequentially
  char *p = code; // pointer at the beginning

  while(*p!='\0'){ // while it's not at the end
    int command = whichFunc(&p);
    if(command<0) printf("command didn't work/not found?");
  }
}


// gets the string of spaces, tabs, and new lines
char * readFile(char* fileName){
  int file = open(fileName, O_RDONLY , 0);
  if(file == -1){
    // prints "Error #: Error message here"
    printf("Error %d: %s\n", errno, strerror(errno));
  }

  char* buff = malloc(1024*4); // make files later, see if we need more
  // add error msg if the malloc didnt work
  if (buff==NULL){
    perror("didn't malloc buff correctly");
  }
  int len = 0; // used to go through the buffer

  char space;
  while(read(file,&space,1)==1){ // while there's something to read
    if(space==' ' || space=='\n' || space=='\t'){ // tabs?????
      buff[len]=space;
      len++;
      /*if(space==' ') printf("[Space]");
      if(space=='\n') printf("[LF]\n");
      if(space=='\t') printf("[Tab]");*/
    }
  }

  buff[len] = '\0';
  close(file);
    return buff;
  }







int whichFunc(char** p){ // points to where we are in the string

  char *ptr = *p;

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
    return 1;
  }
  // stack manipulation
  else if (*ptr==' '){
<<<<<<< HEAD:whitespace.c
    if (*(ptr+1)==' ' && *(ptr+2)=='i'){ // from there until new line is the number
=======
    if (*(ptr+1)==' '){
>>>>>>> f3e125f5c24977f81d1a137d5a1553cc3c2a074c:interpreter/whitespace.c
      // push number onto stack
      int number = findNumber((ptr+2));
      push(&stack, number);
    }
    if (*(ptr+1)=='\n' && *(ptr+2)==' '){
      // duplicate top item on stack
      duplicate(&stack);
    }
    if (*(ptr+1)=='\n' && *(ptr+2)=='\t'){
      // swap 2 top items on stack
      swap(&stack);
    }
    if (*(ptr+1)=='\n' && *(ptr+2)=='\n'){
      // discard top item on stack
      discard(&stack);
    }
<<<<<<< HEAD:whitespace.c
    if (*(ptr+1)==' ' && *(ptr+2)=='i'){ // number later
=======
    if (*(ptr+1)==' '){
>>>>>>> f3e125f5c24977f81d1a137d5a1553cc3c2a074c:interpreter/whitespace.c
      // Copy nth item on the stack onto top of stack
      int number = findNumber((ptr+2));
      copy(&stack, number);
    }
<<<<<<< HEAD:whitespace.c
    if (*(ptr+1)=='\n' && *(ptr+2)=='i'){ // number later
=======
    if (*(ptr+1)=='\n'){
>>>>>>> f3e125f5c24977f81d1a137d5a1553cc3c2a074c:interpreter/whitespace.c
      // Slide n items off the stack, keeping top item
      int number = findNumber((ptr+2));
      slide(&stack, number);
    }
    ptr+=3;
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
    return 1;
  }
  // flow control
  else if (*ptr=='\n'){
<<<<<<< HEAD:whitespace.c
    if (*(ptr+1)==' ' && *(ptr+2)==' ' && *(ptr+3)=='l'){ 
      // Mark a location in program
      ptr+=3;
    }
    if (*(ptr+1)==' ' && *(ptr+2)=='\t' && *(ptr+3)=='l'){ 
      // Call a subroutine
      ptr+=3;
    }
    if (*(ptr+1)==' ' && *(ptr+2)=='\n' && *(ptr+3)=='l'){ 
      // Jump unconditionally to a label
      ptr+=3;
    }
    if (*(ptr+1)=='\t' && *(ptr+2)==' ' && *(ptr+3)=='l'){ 
      // Jump to a label if the top of the stack is zero
      ptr+=3;
    }
    if (*(ptr+1)=='\t' && *(ptr+2)=='\t' && *(ptr+3)=='l'){ 
=======
    if (*(ptr+1)==' ' && *(ptr+2)==' ' && *(ptr+3)=="label?"){
      // Mark a location in program
      ptr+=3;
    }
    if (*(ptr+1)==' ' && *(ptr+2)=='\t' && *(ptr+3)=="label?"){
      // Call a subroutine
      ptr+=3;
    }
    if (*(ptr+1)==' ' && *(ptr+2)=='\n' && *(ptr+3)=="label?"){
      // Jump unconditionally to a label
      ptr+=3;
    }
    if (*(ptr+1)=='\t' && *(ptr+2)==' ' && *(ptr+3)=="label?"){
      // Jump to a label if the top of the stack is zero
      ptr+=3;
    }
    if (*(ptr+1)=='\t' && *(ptr+2)=='\t' && *(ptr+3)=="label?"){
>>>>>>> f3e125f5c24977f81d1a137d5a1553cc3c2a074c:interpreter/whitespace.c
      // Jump to label if the top of the stack is negative
      ptr+=3;
    }
    if (*(ptr+1)=='\t' && *(ptr+2)=='\n'){
      // End subroutine & transfer control back to caller
      ptr+=2;
    }
    if (*(ptr+1)=='\n' && *(ptr+2)=='\n'){
      // End program
      ptr+=2;
    }
    ptr+=1;
    return 1;
  }

  *p = ptr;
  return -1; // nothing worked

}



// used for execvp
void parse_args( char * line, char ** arg_ary ){
  char *token;
  int i = 0;
  while((token = strsep(&line, " "))!=0){
    // put token into array arg_ary
    arg_ary[i] = token;
    i++;
  }
  arg_ary[i] = NULL;
}






// might not need this here, was just used for testing in main
int findNumber(char* str){
  int num = 0;
  int sign = 1;
  char * ptr = str;
  if (*ptr == '\t') sign=-1;
  ptr++;
  while (*ptr != '\n' && *ptr != '\0'){
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
