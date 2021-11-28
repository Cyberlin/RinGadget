#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int errno;
int error_factory();
int main(int argc, char* argv[])
{
		//FILE* file;
		//file = fopen("unexist.txt", "rb");
		//if (file == NULL) {
		//		error_factory();
		//		perror("colin says the errno is");
		//		fprintf(stderr, "colin is here %d\n", errno);
		//} else {
		//		fclose(file);
		//}
		fprintf(stderr, "colin is here %d\n", errno);
		return 0;
}

