#include <stdio.h>
int main(){
	//create two arrays,one in int ,one in char 
	int value[] = {10,489,10,58};
	char letters[] ={'z','e','d','i','s','i','d','i'};
	char name[] ="colin";
	printf("the size of name is %lu\n",sizeof(name));
	printf("the size of letters is %lu\n",sizeof(letters));
	printf("the size of value is %lu\n",sizeof(value));
	printf("the size of int is %lu\n",sizeof(int));
	printf("the size of value is %lu\n",sizeof(char));
	printf("the value is %s\n",letters);
	return 0;
}
