#include "whitespace.h"


int main(int argc, char const *argv[]){
  if (argc<=1){
    printf("\nUse either option '-p' to print the translated Whitespace or '-r' to run the translated command.");
  }
  if (argc>1 && strcmp(argv[1],"-p")==0){ // first argument is 'p', print the translated
    /*char translated[] = "hi"; // replace with function call
    printf("%s", translated);*/
    char * stringOf = readFile("test.txt");
    printf("%d",findNumber(stringOf));
  }
  if (argc>1 && strcmp(argv[1],"-r")==0){ // first argument is 'r', runs the translated command
    // uses function on a string and then calls execvp successfully
    char * args[1024*4]; // change later
    char line[] = "echo 'Hello World'"; // this line should come from 
    parse_args(line, args); // feeds in lines, returns args
    execvp(args[0], args);
  }
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


// potentially move to a new file later
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

// gets the string of spaces, tabs, and new lines
char * readFile(char* fileName){
  int file = open(fileName, O_RDONLY , 0);
  if(file == -1){
    // prints "Error #: Error message here"
    printf("Error %d: %s\n", errno, strerror(errno));
  }

  char* buff = malloc(1024*4); // make files later, see if we need more
  // add error msg if the malloc didnt work
  int len = 0; // used to go through the buffer

  char space;
  while(read(file,&space,1)==1){ // while there's something to read
    if(space==' ' || space=='\n' || space=='\t'){
        len+=1;
        buff[len]=space;
    }
  }
  buff[len]='\0';
  close(file);
    return buff;
  }

  struct space_node * linkList(char *strIn){
    struct space_node *head = NULL;
    struct space_node *curr = NULL;

    // go through everything in the string except idk how... while something
    // inside the loop:
    struct space_node *new = malloc(sizeof(struct space_node));
    // throw error if it doesnt malloc right

    if(head==NULL){
      head=new;
    }
    else{
      curr->next=new;
    }
    return head;
  }