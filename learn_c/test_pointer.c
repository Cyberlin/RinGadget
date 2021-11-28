#include <stdio.h>
#include <string.h>
int main()
{
		int src = 9;
		printf("the address of src is %p\n", &src);
		int* p = (int*)0x7fd748b00c;
		*p = 5;
		int **pp = &p;
		printf("the address of p is %p\n", p);
		printf("the value of %d", *p);
		return 0;
}
