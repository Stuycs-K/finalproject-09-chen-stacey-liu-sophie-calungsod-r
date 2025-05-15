#include "whitespace.h"


int main(){
    // RUN A COMMAND THAT READS THE WHITESPACE IF AN OPTION IS USED TO DO THAT, THEN PUT THAT INTO LINE[]
    // otherwise just print the whitespace
  // uses function on a string and then calls execvp successfully
  char * args[256];
  char line[] = "echo 'Hello World'"; // this line should come from 
  parse_args( line, args ); // feeds in lines, returns args
  execvp(args[0], args);
}

// potentially move to a new file later
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


/*void readFile(char* fileName) {
    FILE *input = fopen(fileName, "r");
    if (input==NULL){
        perror("can't open file");
    }

    char* space;
    int read = 
    while (read(&space, 1, 1, input)==1) { // one byte at a time
        if(space==' ') printf("space");
        // do new line stuff
    }
    fclose(input);
}*/

// doesnt work yet
int readFile(char* fileName){
  int space;
  int file = open(fileName, O_RDONLY , 0);
  if(file == -1){
    // prints "Error #: Error message here"
    printf("Error %d: %s\n", errno, strerror(errno));
  }
  if (read(file, &space, sizeof(int)) == -1) printf("Error %d: %s\n", errno, strerror(errno));
  printf(space);
  close(file);
  return 0;
}