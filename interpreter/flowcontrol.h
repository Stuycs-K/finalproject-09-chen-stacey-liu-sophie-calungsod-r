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

#ifndef flowcontrol
#define flowcontrol

#define ARRAY_SIZE 100
struct labelInfo {
    char * label_name;
    char * label_ptr;
};
char * findLabel(char * ptr);
void markLoc(struct labelInfo * label_ary, char* label, char* ptr);
// void callSubRoutine(char ** label_ary, char * label, char* ptr);
void unCondJump(char * label, struct labelInfo * label_ary, char ** currPtr);
// void zeroJump(Stack *stack, char * label);
// void negJump(Stack *stack, char * label);
void printLabelAry(struct labelInfo * label_ary);
#endif
