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
#define MAX 1024
void shellLoop(void); //declaration for our shell loop
char *command(void);
int exitShell(void);
//As we know a shell is actually just a while loop

int main(void){
	shellLoop();
}

void shellLoop(void){
	bool shellRunning = true;
	char *user = NULL;
	/*
	Usually shells allow users to enter word like 'quit', 'QUIT', 'q', or 'Q' if they want to exit the loop.
	Lets have a loop, now our loop could either be a while or do...while loop, but lets work with a while loop first
	*/
	while(shellRunning){ //based on a condition our loop/shell will still run

		user = command();
		printf("%s",user);
		//Here we are going to handle exit shell
		/*
		Now the thing about this exit is that in an actal shell such as bash,
		a user is able to enter something like 'quit shell' and it seems like
		it looks at only the first word and if that is the same as 'quit' then it
		automatically quits the shell
		*/
	}
}

char *command(void){
	char *user = malloc(sizeof(char)*MAX); //Hold up to 1024 bytes

	//Ensure user is not pointing to NULL
	if(!user){
		printf("Unexpected Error");
		exit(EXIT_FAILURE);
	}
	fgets(user,MAX,stdin);
	return user;
}

//Here we will have a function to handle the exit
int exitShell(void){
	return 0;
}
