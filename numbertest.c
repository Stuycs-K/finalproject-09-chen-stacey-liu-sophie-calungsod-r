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
