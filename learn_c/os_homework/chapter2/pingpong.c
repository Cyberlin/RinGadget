#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MAX 128
int main(int argc,char *argv[]){
		char output[MAX];
		char input[MAX]="LOVINGOS";
		int pid,fd[2];
		pipe(fd);
		while((pid =fork())==-1);
		if(pid==0){
				write(fd[1],input,MAX);
				exit(0);
		}else{
				wait(0);
				read(fd[0],output,MAX);
				printf("<%d>: %s\n",getpid(),output);
				exit(0);
		}

}
