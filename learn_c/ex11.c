#include <malloc.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
		int n = 0;
		scanf("%d", &n);
		//create a new array dynamically
		//int test[n];
		//for (int i = 0; i < n; i++) {
		//		test[i] = i;
		//}
		//n--;
		//while (n != 0) {
		//		printf("src:i::%d\n", src[n]);
		//		n--;
		//}
		//shallow copy and deep copy
		//let us create a src array
		char* src[] = { "math", "physical", "history", "chemistry", NULL };
		int len = 0;
		char* tem = src[0];
		while (tem) {
				tem = src[len];
				len++;
		}
		len--;
		//dest is array of char* ,you can consider that is a 2D array
		char** dest = (char**)malloc(len * sizeof(char*));
		//deep copy,here the src[i] is null ,so segfault occurs
		for (int i = 0; i < len; i++) {
				dest[i] = strdup(src[i]);
		}
		for (int i = 0; i < len; i++) {
				printf("dest[%d]:%s\n", i, dest[i]);
		}
		//free the malloc
		if (dest != NULL) {
				for (int i = 0; i < len; i++) {
						free(dest[i]);
				}
				free(dest);
		}

		//char* name = "colin";
		//char colin[40];
		//be careful the buffer overflow
		//strcpy(colin, name);
		//printf("the colin is %s\n", colin);
		//while(tem){
		//		len++;
		//		tem = argv[len];
		//		strcpy(value[len], tem);
		//		printf("%s\n",value[len]);
		//}
		//for (int i = 0;i<len;i++){
		//		printf("%s\n",value[i]);
		//}
		return 0;
}

