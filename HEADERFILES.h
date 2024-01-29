#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<signal.h>
#include<dirent.h>
#include<sys/socket.h>
#include<sys/ioctl.h>
#include<net/if.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<ifaddrs.h>
#include<netdb.h>
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
void exitShell(void);
void dir(void);
void view(char * args);
void getIPAddress(void);
void networkScan(void);
void flushShell(void);
void listWirelessNetworks();
