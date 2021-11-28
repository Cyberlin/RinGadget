#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int errno;
int main(int argc, char* argv[])
{
		FILE* file;
		file = fopen("unexist.txt", "rb");
		if (file == NULL) {
				perror("colin says the errno is");
		}
		fclose(file);
		return 0;
}
