#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
		int p;
		putchar('x');
		putchar('\n');
		while ((p = fork()) == -1)
				;
		if (p == 0) {
				printf("I am child ,my pid is : %d\n", getpid());
				printf("Now I will exec the child\n");
				execl("./child", 0);
		} else {
				printf("I am parent ,my pid is %d\n", getpid());
				printf("I will wait for my child\n");
				wait(0);
				exit(0);
		}
		return 0;
}
