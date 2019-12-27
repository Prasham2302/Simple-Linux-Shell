#include <unistd.h>

int ls(char c[10][100]){
	if(strcmp(c[1],"-a")==0){
		execl("/bin/ls","ls","-a",NULL);
	}
	else if(strcmp(c[1],"-l")==0){
		execl("/bin/ls","ls","-l",NULL);
	}
	else {
		execl("/bin/ls","ls",0,NULL);
	}
}