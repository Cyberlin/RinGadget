#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char* argv[])
{
		//check the argc
		if (argc != 2) {
				fprintf(stderr, "Usage: %s <FileName>", argv[0]);
				exit(EXIT_FAILURE);
		}
		//initial the stat struct
		struct stat file_info;
		//read from the struct and output it
		if (stat(argv[1], &file_info) == -1) {
				perror("stat() error");
				exit(EXIT_FAILURE);
		}
		printf("Inode num: %ld\n", (long)file_info.st_ino);
		printf("Dev num: %ld\n", (long)file_info.st_dev);
		printf("user id num: %ld\n", (long)file_info.st_uid);
		printf("block num: %lld\n", (long long)file_info.st_blocks);

		return 0;
}
