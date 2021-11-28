#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
		//what if the array is allocated dynamically
		char* strs[4];
		for (int i = 0; i < 4; i++) {
				char str[20];
				strs[i] = str;
		}
		for (int i = 0; i < 4; i++) {
				scanf("%s",strs[i]);
		}

		int count_strs = sizeof(strs)/sizeof(strs[0]);
		printf("the length of strs is %d\nthe sizeof(strs[0]) is %lu\n", count_strs,sizeof(strs[0]));
		//printf("the count of strs is: %d",count_strs);
		//we can get the sizeof names because it is a statically allocated array
		int age[] = { 12, 23, 45, 56 };
		char* names[] = { "sliversdfsdfdsfsdfdsfsdfsdf", "colin", "ray", "john" };
		char** cur_name = names;
		int count_age = sizeof(age) / sizeof(int);
		printf("the length of names  : %lu\n", sizeof(names) / sizeof(names[0]));
		for (int i = 0; i < count_age; i++) {
				printf("the age:%s\n", *(cur_name + i));
		}
		return 0;
}
