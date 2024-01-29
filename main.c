#include"HEADERFILES.h"
#define clearTerminal() printf("\033[H\033[J")
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
//void initBool(void){
static enum boolean false = FALSE;
static enum boolean true = TRUE;
static enum boolean isMultipleCharacter = FALSE;
static enum boolean isIPV4 = TRUE;

void clear(void){
	//to clear out terminal
	sleep(3);
	clearTerminal();
}

void exitShell(void){
	//Now to be able to exit our program, we cna use the exit function
	exit(EXIT_SUCCESS);
}

void flushShell(void){
	char c;
	while((c = getchar()) && (c != '\n') && (c != EOF));
	printf("%c",c);
	return;
}

void dir(void){
	//This part is going to be more challenging, as we want to list the directories and files in the current directory
	//https://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
	//Example usage: https://www.geeksforgeeks.org/c-program-list-files-sub-directories-directory/
	DIR *dirp = opendir(getcwd(NULL,0)); //represents directory stream
	struct dirent *de;
	if(dirp == NULL){
		printf("Unable to open directory");
		return;
	}

	while((de = readdir(dirp)) != NULL){
		printf("%s\t",de->d_name);
	}
	printf("\n");
	closedir(dirp);
	return;
}

//later make another type of dir, that will allow user to list dirctories and files ina specific location/path


//in bash, we can use the cat to view a file, well, i will create one called view
void view(char *args){
	//Now this will require just reading a file, first we will check if our file exist
	printf("Do this later as this require 2 arguments, e..g view [filename]");
}

void getIPAddress(void){
	//just for fun (Get device IP address)
	//now we can be able to fetch data from an API or something like that

	socklen_t endpoint;
	struct ifreq ifr;
	char * interface = "eth0";
	endpoint = socket(AF_INET, SOCK_DGRAM,0);
	if(endpoint == -1){
		printf("Unable to create socket");
		return;
	}
	//else{
	//	printf("Socket successfuly created");
	//}

	ifr.ifr_addr.sa_family = AF_INET;
	strncpy(ifr.ifr_name, interface, IFNAMSIZ-1); //IFNAMSIZ is the size of the interface name in the ifr_name
	ioctl(endpoint, SIOCGIFADDR, &ifr);
	close(endpoint);
	printf("%s - %s\n", interface, inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr)->sin_addr) );
	return;

}

//Having issue with the networkScan function, so we are going to focus on that

void ipInfo(void){
	//find network within range
	socklen_t endpoint, networkInterfaceInit, family, familySize, s;
	endpoint = socket(AF_INET, SOCK_DGRAM,0);
	if(endpoint == -1){
		printf("Unable to create socket");
		return;
	}
	//We have access to the getifaddrs function whichs create a linked list, and what we can do is create a structure of type ifaddrs which has the following properties:
	/*
	ifa_next
	ifa_name
	ifa_flags
	ifa_addr
	ifa_addr
	ifa_netmask
	union ifa_ifu -> contains 2 inner-structures
	*/

	//So what i am going to do is a huge test

	struct ifaddrs *address;
	//getifaddrs returns -1 on failure. It takes a pointer that points to a pointer(So can just pass in the memory address)
	networkInterfaceInit = getifaddrs(&address);
	if(networkInterfaceInit == -1){
		printf("getifadds call failed");
		return;
	}

	printf("Testing\n");

	printf("Searching for network...\n");
	//sleep(2);
	//struct ifaddrs *_address = address;
	//while(_address){
	for(struct ifaddrs *_address = address; _address !=NULL; _address = _address->ifa_next){
		if(_address->ifa_addr == NULL){
			continue;
		}
		family = _address->ifa_addr->sa_family;
		if(family == AF_INET || family == AF_INET6){
			printf("%s\t", _address->ifa_name);
			if(family != AF_INET){
				isIPV4 = FALSE;
			}
			//printf("testing top\n");

			if(isIPV4){
				printf("IPv4\t");
				familySize = sizeof(struct sockaddr_in);
			}
			else{
				printf("IPV6");
				familySize = sizeof(struct sockaddr_in6);
			}
			//printf("Testing bottom\n");
			char ap[NI_MAXHOST];//malloc(sizeof(char)*1024);
			//getnameinfo(_address->ifa_addr,familySize, ap, sizeof(ap), 0,0, NI_NUMERICHOST);
			s = getnameinfo(_address->ifa_addr,familySize,ap,NI_MAXHOST,NULL,0,NI_NUMERICHOST);
			if(s !=0){
				printf("getnameinfo() failed: %s\n", gai_strerror(s));
			}
			printf("\t%s\n",ap);
		}
		else{
			("Unable to get information for this particular host");
		}
		//_address = _address->ifa_next;
	}
	//freeifaddrs(address);
	//freeifaddrs(address);
	/*

	*/
	//lets free the memory space
	//Now what i am going to do for now, since i have tried everything is a temporary fix
	freeifaddrs(address);
	//fflush(stdout);
	/*int wait = 5;
	printf("Please wait");
	while(wait !=0){
		printf(".");
		wait-=1;
		sleep(2);
	}*/
	//freeifaddrs(address);
	sleep(5);
	system("./temp.sh");
	//return;
	exit(EXIT_SUCCESS);
}

void listWirelessNetworks(){
	printf("To list wireless networks");
}

void display(void){
	//printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
	//printf("#    #\n#    #\n# # # # \n#    #\n#    #\n#    #\n");
	printf(ANSI_COLOR_RED"              ╔╗  ╔═══╗\n"
	"║║ ║║         ║║  ║╔═╗║\n"
	"║╚═╝║╔══╗ ╔══╗║╚═╗║║ ╚╝╔══╗╔══╗\n"
	"║╔═╗║╚ ╗║ ║══╣║╔╗║║║ ╔╗║╔╗║║╔╗║\n"
	"║║ ║║║╚╝╚╗╠══║║║║║║╚═╝║║╚╝║║║║║\n"
	"╚╝ ╚╝╚═══╝╚══╝╚╝╚╝╚═══╝╚══╝╚╝╚╝\n" ANSI_COLOR_RESET "\n");
	//will display IP address
	getIPAddress();
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
	//printf("Length of args1 is %i and args2 is %i",length,args2length);
	//now lets check that length and args2length are the same, otherwise, it will not be the same command
	if(length != args2length){
		printf("Not same length %i %i", length,args2length);
		return -1;
	}

        for(int i=0; i< length-1; i++){ //due to some unwanted bug, i made it to be length-1 (so it will not compare the '\0'
		//printf("%c   %c\n",args1[i],args2[i]);
		if(args1[i] != args2[i]){
			//printf("%c,%c",args1[i],args2[i]);
			return -1;
		}
        }
	return 0;
}

void parseSingleInput(char *args, int length){
	//printf("To parse inputs");

	if(stringCompare(args,"cls",length) == 0){
		printf("%s\n",args);
		cls();
		return;
	}
	else if(stringCompare(args,"exit",length) == 0){
		printf("%s\n",args);
		exitShell();
		return;
	}
	else if(stringCompare(args,"ls",length) == 0){
		printf("%s\n",args);
		dir();
		return;
	}
	else if(stringCompare(args,"ip",length) == 0){
		printf("%s\n",args);
		getIPAddress();
		return;
	}
	else if(stringCompare(args,"ipScan",length) == 0){
		printf("%s\n",args);
		ipInfo();
		return;
	}
	else{
		printf("%s\n",args);
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
		isMultipleCharacter = FALSE;
        }

        while(true);
        cwd();
}

int main(int argc, char ** argv){
	clearTerminal();
	display();
	getUserEnvironmentVariable();

	mainLoop();
	return 0;
}

