#include"HEADERFILES.h"
#define clearTerminal() printf("\033[H\033[J")

//void initBool(void){
static enum boolean false = FALSE;
static enum boolean true = TRUE;
static enum boolean isMultipleCharacter = FALSE;

void clear(void){
	//to clear out terminal
	clearTerminal();
}

void display(void){
	//printf("#    #\n#    #\n# # # # \n#    #\n#    #\n#    #\n");
	printf("              ╔╗  ╔═══╗\n"
	"║║ ║║         ║║  ║╔═╗║\n"
	"║╚═╝║╔══╗ ╔══╗║╚═╗║║ ╚╝╔══╗╔══╗\n"
	"║╔═╗║╚ ╗║ ║══╣║╔╗║║║ ╔╗║╔╗║║╔╗║\n"
	"║║ ║║║╚╝╚╗╠══║║║║║║╚═╝║║╚╝║║║║║\n"
	"╚╝ ╚╝╚═══╝╚══╝╚╝╚╝╚═══╝╚══╝╚╝╚╝\n");
}

void printUserDes(char* s1, char* s2, char* s3){
	printf("%s%s%s$ ",s1,s2,s3);
}

void releaseResources(char* a){
	free(a);
}

void getUserEnvironmentVariable(void){
	char * User = getenv("USER");
	char * addSign = ":";
	//printf("%s\n",addSign);
	char * getPath = getcwd(NULL,0);
	if(getPath == NULL){
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	//printf("%s\n",getPath);
	printUserDes(User,addSign,getPath);
}


//lets get some input from users
char* getInput(void){
	//I am going to try and do it the hard way
	char c;
	int buffer = 1024;
	int pointer = 0;
	char * userInput = malloc(sizeof(char)*buffer);
	if(userInput == NULL){
		perror("Coud not allocate Space");
		exit(EXIT_FAILURE);
	}

	while(true){
		c = getchar();
		if(c == EOF || c == '\n'){
			userInput[pointer] = '\n'; //for null terminating character
			//return userInput;
			break;
		}
		userInput[pointer] = c;
		pointer++;
		//resize if pointer greater than buffer size
		if(pointer >= buffer){
			buffer+=1024;
			userInput = realloc(userInput,buffer);
		}

		//check it was successfully reallocated
		if(userInput == NULL){
			perror("Could not reallocated space");
			exit(EXIT_FAILURE);
		}
	}
	//add_history(userInput); Will add this functionality later
	return userInput;
}

void cwd(void){
	char * dir = getcwd(NULL,0);
	printf("%s\n",dir);
}

void cls(void){
        //printf("Clear Screen");
        clear();
}

int stringCompare(char *args1, char *args2, int length){
	//create own string compare functin since the strcmp is not doing as expected


	//first lets get the length of args2 since that will be the command we have not got the length of yet
	int args2length = 0;
	for(int i=0; args2[i] != '\0'; i++){
		args2length+=1;
	}
	//remeber to add an extra 1 for the '\0'
	args2length+=1;

	//now lets check that length and args2length are the same, otherwise, it will not be the same command
	if(length != args2length){
		return -1;
	}

        for(int i=0; i< length; i++){
		if(args1[i] != args2[i]){
			return -1;
		}
        }
	return 0;
}

void parseSingleInput(char *args, int length){
	//printf("To parse inputs");

	if(stringCompare(args,"cls",length) == 0){
		cls();
		return;
	}
	else{
		printf("Error: %sCommand could not be found\n",args);
	}
}
void parseMultipleInput(char **args){
	printf("To parse inputs");
}


void mainLoop(void){

        do{
	//get the number of inputs (i.e. if user enters 2 seperate strings such as clear me, or just a single string)
		int length = 0;
		char * userInput = getInput();
		for(int i=0; userInput[i] != '\0'; i++){
			if(userInput[i] == ' '){ //check if it is not a null terminating character
				length+=1;
				isMultipleCharacter =  TRUE; //empty character detected
			}
			else{
				length+=1;
			}
		}
		//length will be the total length of user character

		//lets parse the arguments
		if(!(isMultipleCharacter)){
			//printf("User Entered a single string\n");
			//lets handle single characters first
			parseSingleInput(userInput,length);
		}
		else{
			printf("User Entered Multiple string\n");
			//we will handle multiple characters later
		}
                //printf("%s",getInput());
                getUserEnvironmentVariable();
        }

        while(true);
        cwd();
}

int main(int argc, char * argv){
	clearTerminal();
	display();
	getUserEnvironmentVariable();

	mainLoop();
	return 0;
}

