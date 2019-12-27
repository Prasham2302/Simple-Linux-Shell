#include <unistd.h>

int rm(char c[10][100]){
	if(strcmp(c[1],"-r")==0){
		execl("/bin/rm","rm","-r",c[2],NULL);
	}
	else if(strcmp(c[1],"-v")==0){
		execl("/bin/rm","rm","-v",c[2],NULL);
	}
	else {
		execl("/bin/rm","rm",c[1],NULL);
	}
}