#include "flowcontrol.h"
#include "stack.h"



// int main(){
//   // code for flow control part of whitespace, reference whichFunc() in whitespace.c
//   char * testline = "\n  \t\n\n  \t  \n"; //\n \n\t\n"; <-- test unCondJump(infinite loop)
//   char * testing = "\n  \t"
//   char * ptr= testline; // points to where you are in string/Whitespace code
//   struct labelInfo * label_ary = (struct labelInfo *)malloc(ARRAY_SIZE*sizeof(struct labelInfo)); // keeps track of labels & their pointers
//   struct labelInfo * labelAry_ptr = label_ary;
//   struct labelInfo * returnLabel = (struct labelInfo *)malloc(sizeof(struct labelInfo)); // label to go to when return (NTN) is called
//   Stack stack;
//   init(&stack);
//   while (ptr < testline + strlen(testline)){
//     if (*(ptr) == '\n'){ // if IMP is N, aka flow control
//       if (*(ptr+1) == ' ' && *(ptr+2) == ' '){ // mark location with the label
//         ptr+= 3;
//         char * label = findLabel(ptr);
//         ptr += strlen(label) + 1;
//         markLoc(labelAry_ptr, label, ptr);
//         labelAry_ptr++;
//       }
//       if (*(ptr+1) == ' ' && *(ptr+2) == '\t'){ // call subroutine
//         ptr+= 3;
//         char * label = findLabel(ptr);
//         ptr += strlen(label)+1;
//         markLoc(returnLabel, label, ptr);
//         unCondJump(label, label_ary, &ptr);
//       }
//       if (*(ptr+1) == ' ' && *(ptr+2) == '\n'){ // jump unconditionally
//         ptr+= 3;
//         char * label = findLabel(ptr);
//         unCondJump(label, label_ary, &ptr);
//       }
//       if (*(ptr+1) == '\t' && *(ptr+2) == ' '){ // zero jump
//         //NTS[label]
//         ptr+= 3;
//         char * label = findLabel(ptr);
//         if (pop(&stack) == 0) unCondJump(label, label_ary, &ptr);
//         else ptr += strlen(label)+1;
//       }
//       if (*(ptr+1) == '\t' && *(ptr+2) == '\t'){ // negative jump
//         //NTT[label]
//         ptr+= 3;
//         char * label = findLabel(ptr);
//         if (pop(&stack) < 0) unCondJump(label, label_ary, &ptr);
//         else ptr += strlen(label)+1;
//       }
//       if (*(ptr+1) == '\t' && *(ptr+2) == '\n'){ // end subroutine
//         ptr = returnLabel -> label_ptr;
//       }
//       if (*(ptr+1) == '\n' && *(ptr+2) == '\n'){ // end program
//         return 1;
//       }
//     }
//   }
//   printLabelAry(label_ary);
//   printf("%ld\n", (long int)ptr);
//   return 0;
// }

/* returns a label given the pointer to the beginning of the label */
char* findLabel(char * ptr){
  int strlen = 0;
  while (*(ptr+strlen) != '\n') {
    strlen++;
  }
  char* label = malloc(strlen);
  strncpy(label, ptr, strlen);
  label[strlen] = '\0';
  return label;
}

/* NSS[label]
   adds the label and a pointer to that label to an array
   - label_ary --> the array of labels and their pointers
        => each array in label_ary -> {label, address}
   - label --> the label we're looking for
   - ptr --> pointer to the location of the label in the code
*/
void markLoc(struct labelInfo * label_ary, char* label, char* ptr){
  if (ptr == NULL) perror("Error: Value of pointer is NULL\n");
  if (label == NULL) perror("Error: Value of label is NULL\n");
  struct labelInfo * x = (struct labelInfo *)malloc(sizeof(struct labelInfo));
  x -> label_name = label;
  x -> label_ptr = ptr;
  *(label_ary) = *x;
}

/* NSN[label]
  changes the current pointer to the pointer attached to the given label
    - currPtr --> address of the pointer denoting where we are in the Whitespace code
    - label_ary --> the array of labels and their pointers
    - label --> the label we're jumping to
*/
void unCondJump(char * label, struct labelInfo * label_ary, char ** currPtr){
  for (int i = 0; i<ARRAY_SIZE; i++){
    char * name = label_ary[i].label_name;//*(label_ary+i) -> label_name;
    char * ptr = label_ary[i].label_ptr;
    if (!strcmp(label, name)){
      *currPtr = ptr;
      return;
    }
  }
  perror("Error: Label not found.\n");
}

/* for dev purposes; prints label_ary
*/
void printLabelAry(struct labelInfo * label_ary){
  printf("{");
  for (int i = 0; i<ARRAY_SIZE; i++){
    printf("[%s, %ld] ", (label_ary+i) -> label_name, (long int)((label_ary+ i) ->label_ptr));
  }
  printf("}\n");
}
