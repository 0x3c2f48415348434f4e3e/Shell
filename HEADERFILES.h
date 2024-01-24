#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<signal.h>
void clearTerminal(void);
void getUserEnvironmentVariable(void);
void printUserDes(char* s1, char* s2, char* s3);
//void releaseResources(int a);
void releaseResources(char * a);
//void releaseResources(float a);
char* getInput(void);
enum boolean { FALSE, TRUE};
void display(void);
void cwd(void);
void parseSingleInputs(char *args, int length);
void parseMultipeInputs(char **args);
void mainLoop(void);
void cls(void);
int stringCompare(char* args1, char* args2, int length);
