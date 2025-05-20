#include "numbertest.h"

int main(){
  // [SPACE][TAB][SPACE][SPACE][TAB][SPACE][TAB][TAB]
  char* test = " \t  \t \t\t\n"; // 75
  char* test2 = "\t\t\t  \t \n"; // -50
  printf("%d\n", findNumber(test));
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
