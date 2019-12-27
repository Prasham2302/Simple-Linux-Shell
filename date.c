#include <unistd.h>

int date(char c[10][100]){
	if(strcmp(c[1],"-u")==0){
		execl("/bin/date","date","-u",NULL);
	}
	else if(strcmp(c[1],"-R")==0){
		execl("/bin/date","date","-R",NULL);
	}
	else {
		execl("/bin/date","date",0,NULL);
	}
}