#include <malloc.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
		//input the n
		int n = 0;
		scanf("%d", &n);
		//create the two array
		int src[n][n];
		for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
						src[i][j] = i;
				}
		}
		int dest[n][n];
		for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
						dest[i][j] = src[i][j];
				}
		}
		for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
						printf("dest[%d][%d]:%d\n",i,j,dest[i][j]);
				}
		}

		return 0;
}
