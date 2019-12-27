#include <unistd.h>

int mkdir(char c[10][100]){
	if(strcmp(c[1],"-v")==0){
		execl("/bin/mkdir","mkdir","-v",c[2],NULL);
	}
	else if(strcmp(c[1],"-p")==0){
		execl("/bin/mkdir","mkdir","-p",c[2],NULL);
	}
	else {
		execl("/bin/mkdir","mkdir",c[1],NULL);
	}
}