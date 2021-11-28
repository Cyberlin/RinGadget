#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
	//inital the relative varible like steam,lineptr,cnt
	FILE *stream;
	char *lineptr =NULL;
	ssize_t nread = 0;
	size_t len = 0;
	//check the count of args
	if (argc!=2){
		fprintf(stderr,"Usage :%s <file>\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	//get the stream
	stream = fopen(argv[1],"r");
	//check the stream
	if (stream==NULL){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	//read the file store it with linptr telling the address
	while((nread =getline(&lineptr,&len,stream))!=-1){
		printf("get the length %zd\n",nread);
		fwrite(lineptr,nread,1,stdout);
	}
	free(lineptr);
	fclose(stream);
	exit(EXIT_SUCCESS);
	return 0;
}

