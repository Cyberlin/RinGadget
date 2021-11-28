#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX 128
int main(int argc, char* argv[])
{
		int i, r, j, k, p1, p2, fd[2];
		char buf[MAX], s[MAX];
		pipe(fd);
		while ((p1 = fork()) == -1)
				;
		if (p1 == 0) {
				//to figure out what is mean
				lockf(fd[1], 1, 0);
				sprintf(buf, "Child process p1 is sending msg!\n");
				printf("Child process p1!\n");
				write(fd[1], buf, MAX);
				lockf(fd[1], 0, 0);
				sleep(2);
				printf("<%d> p2 is weakup,parent <%d>\n", getpid(), getppid());
				exit(0);
		} else {
				while ((p2 = fork()) == -1)
						;
				if (p2 == 0) {
						lockf(fd[1], 0, 0);
						sprintf(buf, "Child process p2 is sending msg\n");
						printf("Child process p2\n");
						write(fd[1], buf, MAX);
						lockf(fd[1], 0, 0);
						sleep(2);
						printf("<%d> p2 is weakup,parent <%d>\n", getpid(), getppid());
						exit(0);
				} else {
						int num;
						wait(0);
						if ((num = read(fd[0], s, MAX)) == -1) {
								printf("can't read pipe\n");
						} else {
								printf("Parent %d:%s\n", getpid(), s);
								wait(0);
								if ((num = read(fd[0], s, MAX)) == -1) {
										printf("can't read pipe\n");
								} else {
										printf("Parent %d:%s\n", getpid(), s);
										exit(0);
								}
						}
				}
		}

		exit(0);
}
