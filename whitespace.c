#include "whitespace.h"

int main(){
  // uses function on a string and then calls execvp successfully
  char * args[16];
  char line[] = "echo 'Hello World'";
  parse_args( line, args ); // feeds in lines, returns args
  execvp(args[0], args);
}

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
