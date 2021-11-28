#include "dbg.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mi(int foot, int head)
{

		int sum = 1;
		while (head--) {
				sum = sum * foot;
		}
		return sum;
}
int get_value(char* str, int left, int right)
{
		int sum = 0;
		for (int i = left; i < right; i++) {
				if (str[i] >= '0' && str[i] <= '9') {
						sum += (str[i] - 48) * mi(10, right - i - 1);
				} else {
						return sum;
				}
		}
		return sum;
}

int my_atoi(char* val)
{
		//get the length of val
		int len = 0;
		int temp = val[0];
		while (temp) {
				temp = val[++len];
		}
		log_info("the len of val :%d", len);
		//check the prefix
		//if the prefix is number or + -
		char prefix = val[0];
		if (prefix == '-' || prefix == '+' || prefix > '0' && prefix < '9') {
				//with prefix like - +
				if (prefix == '+') {
						log_info("the get_value() is %d", get_value(val, 1, len));
				}
		} else {
				//default
				return 0;
		}

		// you can go on complusive cast like (int)(value)
		return 0;
}

int main(int argc, char* argv[])
{
		log_info("the atoi is %d", atoi(argv[1]));
		return 0;
}
