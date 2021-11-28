#include "dbg.h"
#include <stdio.h>
void test_fscanf()
{
		char* colin = "colin";
		char temp = colin[0];
		int cnt = 0;
		while (temp != '\0') {
				temp = colin[++cnt];
		}
		printf("the colin is %d\n", cnt);
		printf("please input your name\n");
		char name[256];
		fscanf(stdin, "%s", name);
		log_info("the name is %s", name);
		for (int i = 0; i < 10; i++) {
				log_info("the char is %c", name[i]);
				if (name[i] == '\0') {
						log_info("I am \\0");
				}
		}
		temp = name[0];
		cnt = 0;
		while (temp != '\0') {
				temp = name[++cnt];
		}
		log_info("the name is %d len", cnt);
}
int test_freopen()
{
		printf("the file you want to open: ");
		char filename[256];
		fscanf(stdin, "%s", filename);
		FILE* file = fopen(filename, "r");
		check(file, "can't open the file %s", filename);
		printf("rename :");
		char rename[256];
		fscanf(stdin, "%s", rename);
		//fclose will automatically recycle the resource but won't set the pointer to null
		//so be careful the double free()
		FILE* new_file = freopen(rename, "r", file);
		check(new_file, "can't rebind the file %s", rename);
		log_info("success");
		if (file)
				fclose(file);
		if (new_file)
				fclose(new_file);

		log_info("fclose success");
		return 0;

error:
		if (file)
				fclose(file);
		if (new_file)
				fclose(new_file);
		return -1;
}

int main(int argc, char* argv[])
{
		int ans = test_freopen();
		log_info("the ans is %d", ans);
		return 0;
}
