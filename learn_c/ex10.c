#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++) {
		printf("args : %d : %s \n", i, argv[i]);
	}
	//in c ,you have to consider array as a pointer with block of  memory,
	//do you really think a pointer can holds the information of the size of an array
	char* string_arr[] = {
		"colin", "ray",
		"mrs.song", "john",NULL
	};
	char *tem =string_arr[0];
	int len = 0;
	while (tem){
		printf("the tem is :%s\n", tem);
		len++;
		tem = string_arr[len];
	}
	printf("debug")	;
	printf("the length of arr is %d\n", len);
	int cnt = strlen(string_arr[1]);
	printf("the cnt is %d\n", cnt);
	return 0;
}
