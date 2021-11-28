#include "dbg.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_DATA 100
int read_string(char** data, int max_buffer)
{
		*data = calloc(1, max_buffer + 1);
		check_mem(*data);
		char* result = fgets(*data, max_buffer, stdin);
		check(result != NULL, "Input error");
		return 0;

error:
		if (*data)
				free(*data);
		*data = NULL;
		return -1;
}
int read_int(int* data)
{
		char* input = NULL;
		int rc = read_string(&input, MAX_DATA);
		check(rc == 0, "Can't read the int");
		*data = atoi(input);
		free(input);
		return 0;
error:
		if (input) {
				free(input);
		}
		return -1;
}
int read_scan(const char* fmt, ...)
{

		int rc;
		int* out_int = NULL;
		char* out_char = NULL;
		char** out_string = NULL;
		int max_buffer = 0;
		va_list ap;
		va_start(ap, fmt);
		for (int i = 0; fmt[i] != '\0'; i++) {
				if (fmt[i] == '%') {
						i++;
						switch (fmt[i]) {
						case '\0':
								sentinel("Invalid format.Don't end with %%.");
								break;
						case 'd':
								out_int = va_arg(ap, int*);
								rc = read_int(out_int);
								check(rc == 0, "Fail to read a int");
								break;
						case 'c':
								out_char = va_arg(ap, char*);
								*out_char = fgetc(stdin);
								break;
						case 's':
								max_buffer = va_arg(ap, int);
								out_string = va_arg(ap, char**);
								rc = read_string(out_string, max_buffer);
								check(rc == 0, "Fail to read a string");
								break;
						default:
								sentinel("Invalid format");
						}
				} else {
						fgetc(stdin);
				}
				check(!feof(stdin) && !ferror(stdin), "Input error");
		}
		va_end(ap);
		return 0;
error:
		va_end(ap);
		return -1;
}
int main(int argc, char* argv[])
{
		char* first_name = NULL;
		char* last_name = NULL;
		char inital = ' ';
		printf("What's your first name and last name\n");
		int rc = read_scan("%s%s", MAX_DATA, &first_name, MAX_DATA, &last_name);
		check(rc == 0, "Failed first name");
		printf("Your name: %s\n", first_name);
		printf("Your last name :%s\n", last_name);
		//rc = read_scan("%c",&inital);
		//check(rc==0,"Fail initial");
		return 0;
error:
		if (first_name) {
				free(first_name);
		}
		return -1;
}
