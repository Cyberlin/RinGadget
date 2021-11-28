#include <errno.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int (*compare_cb)(int a, int b);
void die(const char* message)
{
		if (errno) {
				perror(message);
		} else {
				printf("ERROR: %s\n", message);
		}
		exit(-1);
}
int* bubble_sort(int* numbers, int count, compare_cb comparitor)
{
		int* target = malloc(count * sizeof(int));
		memcpy(target, numbers, count * sizeof(int));
		if (!target) {
				die("memory error");
		}
		for (int i = count - 1; i > 0; i--) {
				for (int j = 0; j < i; j++) {
						if (comparitor(target[j], target[j + 1]) > 0) {
								int temp = target[j];
								target[j] = target[j + 1];
								target[j + 1] = temp;
						}
				}
		}
		return target;
}
int normal_ord(int a, int b)
{
		return a - b;
}
int reverse_ord(int a, int b)
{
		return b - a;
}
int bizarre_ord(int a, int b)
{
		if (a == 0 || b == 0) {
				return 0;
		} else {
				return a % b;
		}
}
void test_sorting(int* numbers, int count, compare_cb cmp)
{
		int* sorted = bubble_sort(numbers, count, cmp);
		for (int i = 0; i < count; i++) {
				printf("\t%d", sorted[i]);
		}
		printf("\n");
		free(sorted);
}
int main(int argc, char* argv[])
{
		if (argc < 2)
				die("USAGE: ex18 4 3 1 5 6");

		int count = argc - 1;
		int i = 0;
		char** inputs = argv + 1;

		int* numbers = malloc(count * sizeof(int));
		if (!numbers)
				die("Memory error.");

		for (i = 0; i < count; i++) {
				numbers[i] = atoi(inputs[i]);
		}

		test_sorting(numbers, count, normal_ord);
		test_sorting(numbers, count, reverse_ord);
		//test_sorting(numbers, count, bizarre_ord);

		free(numbers);

		return 0;
}
