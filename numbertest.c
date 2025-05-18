#include "numbertest.h"

int main(){
  char* test = "           \n";
  char* cpyp = " 	  	 		\n";
  printf("%d\n", findNumber(test));
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
      printf("movedspace\n");
      num << 1;
    }
    else if (*ptr == '\t'){ // does it need to be ascii?
      printf("movedtab\n");
      num << 1;
      num++;
    }
    ptr++;
  }
  return sign*num;
}
