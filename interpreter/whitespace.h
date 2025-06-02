#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#ifndef whitespace
#define whitespace

int main(int argc, char *argv[]);
int findNumber(char* str, int * numLen);
char * readFile(char* fileName);
char * readLetterFile(char* fileName);
void printReadable(char * str);
int whichFunc(char** p);
void runProgram(char *code);
struct labelInfo * retrieveLabels(char * ptr); //, struct labelInfo * returnLabel);

#endif
