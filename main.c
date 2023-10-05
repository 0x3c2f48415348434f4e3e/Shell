//Here we are going to be writing a shell

/*
What does a shell do

Well a shell is just a command line interface that allows the user to enter command whihc will can directly communcate the OS.

We will start from simple and then build on
*/

//First thing i will do is just include our standard input/output
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> //POSIX
#include <unistd.h>
#define MAX 1024
int shellLoop(void); //declaration for our shell loop
char *command(void);
int parseCommand(char * val);
int exitShell(void);
char * currenWorkingdirectory = malloc(sizeof(char)*1024);
//Display the files and directory
void displayFiles(void); //Should return an array of strings containing the files and folders

//As we know a shell is actually just a while loop

int main(void){
	shellLoop();
}

int shellLoop(void){
	bool shellRunning = true;
	char *userCommand = malloc(sizeof(char)*MAX);
	//int pointer = 0; Comment this out for now
	/*
	Usually shells allow users to enter word like 'quit', 'QUIT', 'q', or 'Q' if they want to exit the loop.
	Lets have a loop, now our loop could either be a while or do...while loop, but lets work with a while loop first
	*/
	while(shellRunning){ //based on a condition our loop/shell will still run
		userCommand = command();
		char * lfd = "list";
		if(parseCommand(userCommand) == 0){
			//(Testing) printf("\n%s\n",userCommand);
			printf("\nlogout\n");
			shellRunning = false;
		}
		else if(strcmp(userCommand,"lfd")){
			displayFiles();
		}
		//(Testing)printf("\n%s",userCommand);
		//Here we are going to handle exit shell
		/*
		Now the thing about this exit is that in an actal shell such as bash,
		a user is able to enter something like 'quit shell' and it seems like
		it looks at only the first word and if that is the same as 'quit' then it
		automatically quits the shell
		*/
	}
	return exitShell();
}

char *command(void){
	char c;
	int pointer = 0;
	char *command = malloc(sizeof(char)*MAX);
	//command[pointer] = c;
	while(1){
		c = getchar();
		if(c == EOF || c == '\n'){
			command[pointer] = '\0';
			return command;
		}
		*(command+pointer) = c;
		pointer+=1;
	}
	free(command);
}

int parseCommand(char *val){
	char * delimeter = " ";
	char * com = strtok(val,delimeter);
	//Only test the first value to see if it is equal to 'q' or 'Q' or 'QUIT' or 'quit'
	if(strcmp(com,"exit") == 0){
		//(Testing)printf("\n%s is equal to exit\n",val);
		return 0;
	}
	return 1;
}

void displayFiles(void){

//Create structure type
	struct dirent display;
	https://www.gnu.org/software/libc/manual/html_node/Directory-Entries.html
	//If 'list' is entered, it displays only non-hidden files and directories


	//opendir()
	//Concept of my 'list' is that it gets current direcotry and list the
	//direcotry and files in that
	if(getcwd(currenWorkingdirectory, sizeof(1024)) == NULL){
		printf("Something went wrong");
	}
	//Finish this
}
//Here we will have a function to handle the exit
int exitShell(void){
	exit(EXIT_SUCCESS);
}
