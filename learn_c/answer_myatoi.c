#include "dbg.h"
#include <limits.h>
#include <stdio.h>
int myAtoi(char* s)
{
		int i = 0, flag = 1;
		int returnNumber = 0;
		int max = INT_MAX / 10;
		while (s[i] == ' ') {
				i++;
		}
		if (s[i] == '-' || s[i] == '+') {
				flag = 44 - s[i++];
		}
		while (s[i] >= '0' && s[i] <= '9') {
			//check the overflow
		int digital = s[i++] - '0';
		if (returnNumber < max || digital < 8 && returnNumber == max)
		returnNumber = returnNumber * 10 + digital; 
		else
		return flag == 1 ? INT_MAX : INT_MIN;
		}
		return flag * returnNumber;
}
int main(int argc, char* argv[])
{
		log_info("the ans is  %d", myAtoi(argv[1]));
		return 0;
}
