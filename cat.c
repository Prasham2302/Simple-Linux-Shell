#include <unistd.h>

int cat(char c[10][100]){
	if(strcmp(c[1],"-e")==0){
		execl("/bin/cat","cat","-e",c[2],NULL);
	}
	else if(strcmp(c[1],"-A")==0){
		execl("/bin/cat","cat","-A",c[2],NULL);
	}
	else {
		execl("/bin/cat","cat",c[1],NULL);
	}
}