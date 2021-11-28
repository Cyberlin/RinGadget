#include "dbg.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
void test_debug()
{
		debug("you don't have hair ");
		debug("you are %d years old", 37);
}
void test_log_err()
{
		log_err("There are %d problem is %s", 16, "space");
}
int test_check(char* file_name)
{
		FILE* input;
		char* block = NULL;
		block = malloc(100);
		input = fopen(file_name, "r");
		check(input, "Fail to load %s", file_name);
		free(block);
		fclose(input);
		return 0;
error:
		if (block) {
				free(block);
		}
		if (input) {
				fclose(input);
		}
		return -1;
}
int read_str(char* file_name, char* dst, int n)
{
		FILE* src = fopen(file_name, "r");
		check(src, "can't open the %s", file_name);
		while (1) {
				check(fgets(dst, n, src), "can't read the %s", file_name);
				printf("%s\n", dst);
		}
		if (dst)
				free(dst);

		if (src)
				fclose(src);

		return 0;

error:

		if (src)
				fclose(src);

		return -1;
}
int test_sentinel(int code)
{
		char* temp = malloc(100);
		check_mem(temp);
		switch (code) {
		case 1:
				log_info("I should work");
				break;
		default:
				sentinel("I should't work");
		}
		free(temp);
		return 0;
error:
		if (temp) {
				free(temp);
		}
		return -1;
}
int test_mem()
{
		char* test = NULL;
		check_mem(test);
		free(test);
		return 1;
error:
		return -1;
}
int test_check_debug()
{
		int i = 0;
		check_debug(i != 0, "Oops,I am not zero");
		return 0;
error:
		return -1;
}
int main(int argc, char* argv[])
{
		test_debug();
		test_log_err();
		char dst[256];
		read_str(argv[1], dst, 256);
		return 0;
}
