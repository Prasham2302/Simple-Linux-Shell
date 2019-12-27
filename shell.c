#include <stdio.h>
#include <string.h>	
#include <stdlib.h> 
#include <stdbool.h>
#include <unistd.h>
#include "date.c"
#include "ls.c"
#include<sys/wait.h>
#include "rm.c"
#include "mkdir.c"
#include "cat.c"

 

void echo(char toprint[10][100],int c){

	if(toprint[1][0] == '-'){
		//echo -E
		for(int i = 2;i<c;i++){
			int k = 0;
			char temp[100];
			int j = 0;
			while(toprint[i][k] != '\0'){
				if(toprint[i][k] != '"'){
					temp[j] = toprint[i][k];
					j++;
				}
				k++;
			}
			printf("%s", temp);
			printf("%s", " ");
		}
	}
	else if(toprint[1][0] == '*'){
		//use ls command
		ls(toprint);
	}
	else{
		for(int i = 1;i<c;i++){
			int k = 0;
			char temp[100];
			int j = 0;
			while(toprint[i][k] != '\0'){
				if(toprint[i][k] != '"'){
					temp[j] = toprint[i][k];
					j++;
				}
				k++;
			}
			printf("%s", temp);
			printf("%s", " ");
			
		}	
	}
	printf("\n");
	return ;
}

void end(){
	exit(0);
}
void currentdirectory(){
	char cwd[256];
	getcwd(cwd,sizeof(cwd));
	int i = 0;
	printf("%s\n", cwd);
}
void changedirectory(char c[10][100], char home[250]){
	
	if((c[1][0] == '/') || (c[1][0]>='a' && c[1][0]<='z') || (c[1][0]>='A' && c[1][0]<='Z')){
		chdir(c[1]);
	}
	else{
		chdir(home);
	}
}

int getWords(char *base, char target[10][100])
{	
	
	int i = 0;
	int n = 0, j = 0;
	int count = 0 ;

	
	while(base[i] != '\0'){
		if(base[i] != ' '){
			target[n][j++] = base[i];
			count = 0;
		}
		else if(base[i] == ' '){
			if (count == 0){
				target[n][j++] = '\0';
				n++;
				j=0;
				count++;
			}
			else {
				count++;
			}
		}
		i++;
	}
	
	return n;
}
void external(char task[10][100]){
	int pid = fork();
	if(pid<0){
		printf("%s\n", "Invalid input");
	}
	else if(pid == 0){
		if(strcmp(task[0],"date")==0)
{			date(task);
		}
		else if(strcmp(task[0],"ls")==0){
			ls(task);
		}
		else if(strcmp(task[0],"rm")==0){
			rm(task);
		}
		else if(strcmp(task[0],"cat")==0){
			cat(task);
		}
		else if(strcmp(task[0],"mkdir")==0){
			mkdir(task);
		}
	}
	else{
		wait(NULL);
	}

}

int main()
{
	char str[1024];
	char delin[] = " ";
	printf("%s\n","---------- Welcome to my Shell ---------" );
	char task[10][100];
	FILE *fp;
	fp = fopen("filehandling.txt","a+");
	char home[250];
	getcwd(home,sizeof(home));
	printf("%s\n", home);
	do{memset(task, 0, sizeof(task));
		printf("%s", "Prasham@Prasham-laptop: ");
		scanf("%[^\n]%*c", str);
		
		int count = getWords(str,task);
		count++;
		if(strcmp(task[0],"echo")==0){
			echo(task,count);
		}
		else if(strcmp(task[0],"exit")==0){
			end();
		}
		else if(strcmp(task[0],"pwd")==0){
			currentdirectory();
		}
		else if(strcmp(task[0],"cd")==0){
			changedirectory(task,home);
		}
		else if(strcmp(task[0],"date") == 0){
			external(task);
		}
		else if(strcmp(task[0],"ls")==0){
			external(task);
		}
		else if(strcmp(task[0],"rm")==0){
			external(task);
		}
		else if(strcmp(task[0],"mkdir")==0){
			external(task);
		}
		else if(strcmp(task[0],"cat")==0){
			external(task);
		}
		else if(strcmp(task[0],"history")==0){
			if(strcmp(task[1],"-c")==0){
				fp = fopen("filehandling.txt","w+");
			}
			else{
				fseek(fp,0,SEEK_SET);
				char temp = fgetc(fp);
				while(temp != EOF){
					printf("%c",temp);
					temp = fgetc(fp);
				}
			}
		}
		else
			printf("%s\n", "Input not recognized, try again");
		fprintf(fp, "%s\n", task[0]);
		}while(1);
		fclose(fp);
}
