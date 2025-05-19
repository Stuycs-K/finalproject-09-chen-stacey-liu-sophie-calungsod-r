#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <ctype.h>
#include <signal.h>

#ifndef whitespace
#define whitespace
// space node
/*struct space_node{
  struct space_node *next;
};*/
int main(int argc, char const *argv[]);
int findNumber(char* str);
void parse_args( char * line, char ** arg_ary );
char * readFile(char* fileName);
#endif

